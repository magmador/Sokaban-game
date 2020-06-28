#include "main.h"

bool LevelSelect(int levelNumber, int ***map)
{
	int mapStart[MAP_ROW_COUNT][MAP_COL_COUNT];
    //выбор карты уровня
	switch (levelNumber) 
	{
		case LEVEL_1:
		{
			int mapLevel0[MAP_ROW_COUNT][MAP_COL_COUNT] = { MAP1 };
			memcpy(mapStart, mapLevel0, sizeof(mapStart));
			break;
		}
		case LEVEL_2:
		{
			int mapLevel1[MAP_ROW_COUNT][MAP_COL_COUNT] = { MAP2 };
			memcpy(mapStart, mapLevel1, sizeof(mapStart));
			break;
		}
		case LEVEL_3:
		{
			int mapLevel3[MAP_ROW_COUNT][MAP_COL_COUNT] = { MAP3 };
			memcpy(mapStart, mapLevel3, sizeof(mapStart));
			break;
		}
		default:
			return false;
	}
	
    //загрузка карты в map
	*map = (int **)malloc(ROW_MAP_SIZE);
	if (*map == NULL) return false;
	for(size_t row = 0; row < MAP_ROW_COUNT; row++)
	{
		(*map)[row] = (int *)malloc(COL_MAP_SIZE); //выделение памяти под строку
		memcpy((*map)[row], mapStart[row], COL_MAP_SIZE);
	}
	return true;
}
