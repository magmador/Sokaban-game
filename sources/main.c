#include "main.h"

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
	size_t boxCount = 0;
	Object *Boxs; //массив ящиков
	Object *Endpoints; //массив эндпоинтов
	Object Player; //перменная игрока
	for(int row = 0; row < MAP_ROW_COUNT; row++)
	{
		for(int col = 0; col < MAP_COL_COUNT; col++)
		{
			if(boxCount == 0 && map[row][col] == 2)
			{
				boxCount++;
				Boxs = (Object *)malloc(boxCount * sizeof(Object));
			}
			/*if (map[row][col] == 2)
			{
				boxCount++;
				Boxs = (Object *)realloc(,boxCount * sizeof(Object));
			}*/
		}
	}
	printf("%ld\n", boxCount);
	return 0;
}
