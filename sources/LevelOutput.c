#include "main.h"

void LevelOutput(int **map, FILE *logFile)
{
	for(size_t row = 0; row < MAP_ROW_COUNT; row++)
	{
		for(size_t col = 0; col < MAP_COL_COUNT; col++)
		{
			fprintf(logFile, "%2d ", map[row][col]);
		}
		fprintf(logFile, "\n");
	}
}