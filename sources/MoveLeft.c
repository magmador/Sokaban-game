#include "main.h"

bool MoveLeft(int **map, Object* player, size_t bCount, Object* boxs, size_t eCount, Object* endpoints)
{
	if (map[player -> yPos][player -> xPos  - 1] != WALL_MAP_OBJ) //Проверка на стену по направлению движения
	{
		if (map[player -> yPos][player -> xPos   - 1] == BOX_MAP_OBJ) //Проверка на ящик по направлению движения
		{
			if(map[player -> yPos][player -> xPos  - 2] != BOX_MAP_OBJ && map[player -> yPos][player -> xPos  - 2] != WALL_MAP_OBJ) //Проверка на ящик или стену за передвигаемым ящиком
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
				player -> xPos--;
				map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
				for (int i = 0; i < bCount; i++) //Поиск ящика, который передвигает игрок
				{
					if (boxs[i].xPos == player -> xPos && boxs[i].yPos == player -> yPos) 
					{
						boxs[i].xPos--;
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
			player -> xPos--;
			map[player -> yPos][player -> xPos] = PLAYER_MAP_OBJ;
			return true;
		}
	}
	else
	{
		return false;
	}
}