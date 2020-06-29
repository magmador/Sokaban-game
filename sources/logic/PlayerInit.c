#include "main.h"

bool PlayerInit(Object *Player, int **map, int obj)
{
	Player->xPos = 0;
	Player->yPos = 0;
	for (size_t row = 0; row < MAP_ROW_COUNT; row++)
		for (size_t col = 0; col < MAP_COL_COUNT; col++)
		{
			if (map[row][col] == 4)
			{
				Player->xPos = col;
				Player->yPos = row;
				break;
			}
		}
	return (!(Player->xPos && Player->yPos)) ? false : true;
}