#include "main.h"

bool PlayerMove(char* direct, int **map, Object* player)
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
			if (map[player -> yPos  - 1][player -> xPos] != 1)
			{
				map[player -> yPos][player -> xPos] = 0;
				player -> yPos--;
				map[player -> yPos][player -> xPos] = 4;
			}
			break;
		}
		case 2:
		{
			if (map[player -> yPos + 1][player -> xPos] != 1)
			{
				map[player -> yPos][player -> xPos] = 0;
				player -> yPos++;
				map[player -> yPos][player -> xPos] = 4;
			}
			break;
		}
		case 3:
		{
			if (map[player -> yPos][player -> xPos - 1] != 1)
			{
				map[player -> yPos][player -> xPos] = 0;
				player -> xPos--;
				map[player -> yPos][player -> xPos] = 4;
			}
			break;
		}
		case 4:
		{
			if (map[player -> yPos][player -> xPos + 1] != 1)
			{
				map[player -> yPos][player -> xPos] = 0;
				player -> xPos++;
				map[player -> yPos][player -> xPos] = 4;
			}
			break;
		}
		default:
		{
			return false;
		}
	}
	return true;
}
