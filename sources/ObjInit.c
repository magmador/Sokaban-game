#include "main.h"

bool ObjInit(size_t *objCount, Object **Objs, int **map, int obj)
{
	*objCount = 0;
	for (size_t row = 0; row < MAP_ROW_COUNT; row++)
	{
		for (size_t col = 0; col < MAP_COL_COUNT; col++)
		{
			if (*objCount == 0 && map[row][col] == obj)
			{
				(*objCount)++;
				*Objs = (Object *)malloc(*objCount * sizeof(Object));
				(*Objs)[(*objCount) - 1].yPos = row;
				(*Objs)[(*objCount) - 1].xPos = col;
			}
			else if (map[row][col] == obj)
			{
				(*objCount)++;
				*Objs = (Object *)realloc(*Objs, (*objCount) * sizeof(Object));
				(*Objs)[(*objCount) - 1].yPos = row;
				(*Objs)[(*objCount) - 1].xPos = col;
			}
		}
	}
	return *objCount ? true : false;
}