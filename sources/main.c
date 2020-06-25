#include "main.h"

/*typedef struct
   {
        int xPos;
        int yPos;
        int color_number;
   } Object;

   Object *Boxs; //массив ящиков
   Object *Endpoints; //массив эндпоинтов
   Object Player; //перменная игрока*/

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

bool LevelSelect(int levelNumber, int ***map)
{
	int mapStart[MAP_ROW_COUNT][MAP_COL_COUNT];
	switch (levelNumber)
	{
		case 0:
		{
			int mapLevel0[MAP_ROW_COUNT][MAP_COL_COUNT] = { MAP0 };
			memcpy(mapStart, mapLevel0, sizeof(mapStart));
			break;
		}
		case 1:
		{
			int mapLevel1[MAP_ROW_COUNT][MAP_COL_COUNT] = { MAP1 };
			memcpy(mapStart, mapLevel1, sizeof(mapStart));
			break;
		}
		default:
			return false;
	}

	*map = (int **)malloc(ROW_MAP_SIZE);
	if (*map == NULL) return false;
	for(int row = 0; row < MAP_ROW_COUNT; row++)
	{
		(*map)[row] = (int *)malloc(COL_MAP_SIZE); //выделение памяти под строку
		memcpy((*map)[row], mapStart[row], COL_MAP_SIZE);
	}
	return true;
}

int main()
{
	int **map = NULL;
	if(!LevelSelect(0, &map))
	{
		printf("'%s': Level not loaded\n", __FUNCTION__);
		exit(1);
	}
#ifdef DEBUG
	else
	{
		printf("'%s': Level successfully loaded\n", __FUNCTION__);
		LevelOutput(map);
	}
#endif
	return 0;
}
