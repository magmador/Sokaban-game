#include "main.h"

bool InitNetBufferMap(int ***map)
{
	*map = (int **)malloc(ROW_MAP_SIZE);
	if (*map == NULL)
		return false;
	for (size_t row = 0; row < MAP_ROW_COUNT; row++)
	{
		(*map)[row] = (int *)malloc(COL_MAP_SIZE); //выделение памяти под строку
	}
	return true;
}