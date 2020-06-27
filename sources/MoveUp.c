#include "main.h"

bool MoveUp(int **map, Object* player, size_t bCount, Object* boxs, size_t eCount, Object* endpoints)
{
	if (map[player -> yPos  - 1][player -> xPos] != WALL_MAP_OBJ) //Проверка на стену по направлению движения
	{
		if (map[player -> yPos  - 1][player -> xPos] == BOX_MAP_OBJ) //Проверка на ящик по направлению движения
		{
			if(map[player -> yPos  - 2][player -> xPos] != BOX_MAP_OBJ && map[player -> yPos  - 2][player -> xPos] != WALL_MAP_OBJ) //Проверка на ящик или стену за передвигаемым ящиком
			{
				map[player -> yPos][player -> xPos] = SPACE_MAP_OBJ;
				for (int i = 0; i < eCount; i++) //Проверка стоит ли игрок на endpoint-е до передвижения
				{
					if (endpoints[i].xPos == player -> xPos && endpoints[i].yPos == player -> yPos) 
					{
						map[player -> yPos][player -> xPos] = ENDPOINT_MAP_OBJ;
						break;
					}
				}
				player -> yPos--;
				map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
				for (int i = 0; i < bCount; i++) //Поиск ящика, который передвигает игрок
				{
					if (boxs[i].xPos == player -> xPos && boxs[i].yPos == player -> yPos) 
					{
						boxs[i].yPos--;
						map[boxs[i].yPos][boxs[i].xPos] = BOX_MAP_OBJ;
						break;
					}
				}
				return true;	
			}
			else
			{
				return false;
			}
		}
		else
		{
			map[player -> yPos][player -> xPos] = SPACE_MAP_OBJ;
			for (int i = 0; i < eCount; i++) //Проверка стоит ли игрок на endpoint-е до передвижения
			{
				if (endpoints[i].xPos == player -> xPos && endpoints[i].yPos == player -> yPos) 
				{
					map[player -> yPos][player -> xPos] = ENDPOINT_MAP_OBJ;
					break;
				}
			}
			player -> yPos--;
			map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
			return true;
		}
	}
	else
	{
		return false;
	}
}