#include "main.h"

void MapToChar(int **map, NetworkBuffer *InBuffer, char *buf)
{
	for (int i = 0; i < MAP_ROW_COUNT; i++)
		{
			for (int j = 0; j < MAP_COL_COUNT; j++)
				{
					(*InBuffer).map[i * MAP_COL_COUNT + j] = map[i][j];
				}
		}
		memcpy(buf, InBuffer, MAP_SIZE + sizeof(bool) + sizeof(int));
}