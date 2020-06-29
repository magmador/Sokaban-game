#include "main.h"

void CharToMap(int **map, NetworkBuffer *OutBuffer, char *buf)
{
	memcpy(OutBuffer, buf, NET_BUF_SIZE);
	for (int i = 0; i < MAP_ROW_COUNT; i++)
	{
		for (int j = 0; j < MAP_COL_COUNT; j++)
		{
			map[i][j] = (*OutBuffer).map[i * MAP_COL_COUNT + j];
		}
	}
}