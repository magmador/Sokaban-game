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
			if (map[player -> yPos  - 1][player -> xPos] != WALL_MAP_OBJ)
			{
				if (map[player -> yPos  - 1][player -> xPos] == BOX_MAP_OBJ)
				{
					if(map[player -> yPos  - 2][player -> xPos] != BOX_MAP_OBJ && map[player -> yPos  - 2][player -> xPos] != WALL_MAP_OBJ)
					{
						map[player -> yPos][player -> xPos] = SPACE_MAP_OBJ;
						for (int i = 0; i < eCount; i++)
						{
							if (endpoints[i].xPos == player -> xPos && endpoints[i].yPos == player -> yPos)
							{
								map[player -> yPos][player -> xPos] = ENDPOINT_MAP_OBJ;
								break;
							}
						}
						player -> yPos--;
						map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
						for (int i = 0; i < bCount; i++)
						{
							if (boxs[i].xPos == player -> xPos && boxs[i].yPos == player -> yPos)
							{
								boxs[i].yPos--;
								map[boxs[i].yPos][boxs[i].xPos] = BOX_MAP_OBJ;
								break;
							}
						}	
					}
					else
					{
						break;
					}	
				}
				else
				{
					map[player -> yPos][player -> xPos] = SPACE_MAP_OBJ;
					player -> yPos--;
					map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
				}
			}
			break;
		}
		case 2:
		{
			if (map[player -> yPos + 1][player -> xPos] != WALL_MAP_OBJ)
			{
				if (map[player -> yPos  + 1][player -> xPos] == BOX_MAP_OBJ)
				{
					if(map[player -> yPos  + 2][player -> xPos] != BOX_MAP_OBJ && map[player -> yPos  + 2][player -> xPos] != WALL_MAP_OBJ)
					{
						map[player -> yPos][player -> xPos] = SPACE_MAP_OBJ;
						player -> yPos++;
						map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
						map[player -> yPos + 1][player -> xPos] = BOX_MAP_OBJ;
					}
					else
					{
						break;
					}	
				}
				else
				{
					map[player -> yPos][player -> xPos] = SPACE_MAP_OBJ;
					player -> yPos++;
					map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
				}
			}
			break;
		}
		case 3:
		{
			if (map[player -> yPos][player -> xPos - 1] != WALL_MAP_OBJ)
			{
				if (map[player -> yPos][player -> xPos - 1] == BOX_MAP_OBJ)
				{
					if(map[player -> yPos][player -> xPos - 2] != BOX_MAP_OBJ && map[player -> yPos][player -> xPos - 2] != WALL_MAP_OBJ)
					{
						map[player -> yPos][player -> xPos] = SPACE_MAP_OBJ;
						player -> xPos--;
						map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
						map[player -> yPos][player -> xPos - 1] = BOX_MAP_OBJ;
					}
					else
					{
						break;
					}	
				}
				else
				{
					map[player -> yPos][player -> xPos] = SPACE_MAP_OBJ;
					player -> xPos--;
					map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
				}
			}
			break;
		}
		case 4:
		{
			if (map[player -> yPos][player -> xPos + 1] != WALL_MAP_OBJ)
			{
				if (map[player -> yPos][player -> xPos + 1] == BOX_MAP_OBJ)
				{
					if(map[player -> yPos][player -> xPos + 2] != BOX_MAP_OBJ && map[player -> yPos][player -> xPos + 2] != WALL_MAP_OBJ)
					{
						map[player -> yPos][player -> xPos] = SPACE_MAP_OBJ;
						player -> xPos++;
						map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
						map[player -> yPos][player -> xPos + 1] = BOX_MAP_OBJ;
					}
					else
					{
						break;
					}	
				}
				else
				{
					map[player -> yPos][player -> xPos] = SPACE_MAP_OBJ;
					player -> xPos++;
					map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
				}
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
