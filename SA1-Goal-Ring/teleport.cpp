#include "pch.h"

//  Check if a player is on a Snowboard:

bool isPlayerOnSnowBoard(char pnum)
{
	auto p = playertwp[pnum];

	if (p)
	{
		auto mde = p->mode;
		if (p->counter.b[1] == Characters_Sonic)
		{
			return mde >= 62 && mde <= 68;
		}
		else if (p->counter.b[1] == Characters_Tails)
		{
			return mde >= 48 && mde <= 54;
		}
	}

	return false;
}


//	Functions for teleporting players:

task* NoColliTp[PLAYER_MAX] = { NULL };

void NoColliDest(task* tp)
{
	anywk* awp = tp->awp;
	NoColliTp[awp->work.sw[0]] = NULL;
}

void NoColliExec(task* tp)
{
	anywk* awp = tp->awp;
	taskwk* ptwp = playertwp[awp->work.sw[0]];

	if (++awp->work.sw[1] >= 2)
	{
		if (ptwp && ptwp->cwp)
		{
			CharColliOn(ptwp);
		}

		FreeTask(tp);
	}
	else
	{
		if (ptwp)
		{
			ptwp->pos = { awp->work.f[1], awp->work.f[2], awp->work.f[3] };
		}
	}
}

void CreateNoColliTp(int pnum, float x, float y, float z)
{
	task* tp = NoColliTp[pnum];

	if (!tp)
	{
		tp = CreateElementalTask(LoadObj_UnknownB, LEV_0, NoColliExec);
		tp->dest = NoColliDest;
		tp->awp->work.sw[0] = pnum;
		NoColliTp[pnum] = tp;
	}
	else if (tp->exec == DestroyTask)
	{
		tp->exec = NoColliExec;
	}

	tp->awp->work.sw[1] = 0;
	tp->awp->work.f[1] = x;
	tp->awp->work.f[2] = y;
	tp->awp->work.f[3] = z;
}

void TeleportPlayer(int pnum, float x, float y, float z)
{
	auto ptwp = playertwp[pnum];
	if (ptwp)
	{
		SetPositionP(pnum, x, y, z);

		// Reset mode except cart/snowboard ones
		if (!isPlayerOnSnowBoard(pnum))
		{
			SetInputP(pnum, PL_OP_LETITGO);
		}

		PClearSpeed(playermwp[pnum], playerpwp[pnum]);
		
		if (ptwp->cwp)
		{
			CharColliOff(ptwp);
			CreateNoColliTp(pnum, x, y, z);
		}
	}
}

void TeleportPlayer(int pnum, NJS_VECTOR* pPos)
{
	TeleportPlayer(pnum, pPos->x, pPos->y, pPos->z);
}

void TeleportPlayers(float x, float y, float z)
{
	for (int i = 0; i < PLAYER_MAX; ++i)
	{
		TeleportPlayer(i, x, y, z);
	}
}

void TeleportPlayers(NJS_VECTOR* pPos)
{
	for (int i = 0; i < PLAYER_MAX; ++i)
	{
		TeleportPlayer(i, pPos->x, pPos->y, pPos->z);
	}
}

void TeleportPlayerArea(int pnum, NJS_POINT3* pin, Float dist)
{
	auto pcount = multi_get_player_count();
	taskwk* ptwp = playertwp[pnum];

	if (!ptwp)
		return;

	NJS_VECTOR pos;

	if (pcount <= 4)
	{
		pos.x = pin->x + njCos(ptwp->ang.y - 0x2000 + 0x4000 * pnum) * dist;
		pos.y = pin->y;
		pos.z = pin->z + njSin(ptwp->ang.y - 0x2000 + 0x4000 * pnum) * dist;
	}
	else if (pcount <= 2)
	{
		pos.y = pin->y;

		if (pnum == 0)
		{
			pos.x = pin->x + njCos(ptwp->ang.y + 0x4000) * dist;
			pos.z = pin->z + njSin(ptwp->ang.y + 0x4000) * dist;
		}
		else
		{
			pos.x = pin->x + njCos(ptwp->ang.y - 0x4000) * dist;
			pos.z = pin->z + njSin(ptwp->ang.y - 0x4000) * dist;
		}
	}
	else
	{
		pos = *pin;
	}

	TeleportPlayer(pnum, &pos);
}

void TeleportPlayersToPlayer(int pnum)
{
	taskwk* ptgt = playertwp[pnum];

	if (ptgt)
	{
		for (int i = 0; i < PLAYER_MAX; ++i)
		{
			taskwk* ptwp = playertwp[i];
			if (ptwp)
			{
				TeleportPlayer(i, &ptgt->pos);
				ptwp->ang.y = ptgt->ang.y;
			}
		}
	}
}

void MovePlayersToWinnerPos(NJS_VECTOR* endpos)
{
	if (multi_is_coop())
	{
		auto pnum = multi_get_winner();

		if (pnum >= 0 && pnum < PLAYER_MAX)
		{
			taskwk* winner = playertwp[pnum];
			NJS_VECTOR pos = winner->pos;

			for (int i = 0; i < PLAYER_MAX; ++i)
			{
				taskwk* ptwp = playertwp[i];
				if (ptwp && GetDistance(endpos, &ptwp->pos) > 40.0f)
				{
					ptwp->ang.y = winner->ang.y;
					TeleportPlayerArea(i, &pos, 8.0f);
				}
			}
		}
	}
}