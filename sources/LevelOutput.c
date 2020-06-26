#include "main.h"

void LevelOutput(int **map)
{
	for(int row = 0; row < MAP_ROW_COUNT; row++)
	{
		for(int col = 0; col < MAP_COL_COUNT; col++)
		{
			printf("%2d ", map[row][col]);
		}
		printf("\n");
	}
}