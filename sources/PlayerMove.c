#include "main.h"

bool PlayerMove(char* direct, int **map, Object* player, size_t bCount, Object* boxs, size_t eCount, Object* endpoints)
{
	int tmpDirect = 0;
	if (!strcmp(direct,"up"))
	{
		tmpDirect = 1;
	}
	else if (!strcmp(direct,"down"))
	{
		tmpDirect = 2;
	}
	else if (!strcmp(direct,"left"))
	{
		tmpDirect = 3;
	}
	else if (!strcmp(direct,"right"))
	{
		tmpDirect = 4;
	}
	switch (tmpDirect)
	{
		case 1:
		{
			if (MoveUp(map, player, bCount, boxs, eCount, endpoints))
			{
				return true;
			}
			break;
		}
		case 2:
		{
			if(MoveDown(map, player, bCount, boxs, eCount, endpoints))
			{
				return true;
			}
			break;
		}
		case 3:
		{
			if(MoveLeft(map, player, bCount, boxs, eCount, endpoints))
			{
				return true;
			}
			break;
		}
		case 4:
		{
			if(MoveRight(map, player, bCount, boxs, eCount, endpoints))
			{
				return true;
			}
			break;
		}
		default:
		{
			return false;
		}
	}
}