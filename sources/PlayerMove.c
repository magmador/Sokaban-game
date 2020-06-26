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
			MoveUp(map, player, bCount, boxs, eCount, endpoints);
			break;
		}
		case 2:
		{
			MoveDown(map, player, bCount, boxs, eCount, endpoints);
			break;
		}
		case 3:
		{
			MoveLeft(map, player, bCount, boxs, eCount, endpoints);
			break;
		}
		case 4:
		{
			MoveRight(map, player, bCount, boxs, eCount, endpoints);
			break;
		}
		default:
		{
			return false;
		}
	}
	return true;
}