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
	Object *Boxs; //массив ящиков
	Object *Endpoints; //массив эндпоинтов
	Object Player; //перменная игрока

	size_t boxCount;
	if(!ObjInit(&boxCount, &Boxs, map, BOX_MAP_OBJ))
	{
		printf("'%s': Can't initialize object Boxs\n", __FUNCTION__);
		exit(1);
	}
#ifdef DEBUG
	else
	{
		printf("'%s': Object Boxs successfully initialized\n", __FUNCTION__);
		for(int i = 0; i < boxCount; i++) printf("%d:%d ", Boxs[i].yPos, Boxs[i].xPos);
		printf("\n");
	}
#endif

	size_t endpointCount;
	if(!ObjInit(&endpointCount, &Endpoints, map, BOX_MAP_OBJ))
	{
		printf("'%s': Can't initialize object Endpoints\n", __FUNCTION__);
		exit(1);
	}
#ifdef DEBUG
	else
	{
		for(int col = 0; col < MAP_COL_COUNT; col++)
		{
			if(map[row][col] == 4)
			{
				Player.xPos = col;
				Player.yPos = row;
			}
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
		printf("'%s': Object Endpoints successfully initialized\n", __FUNCTION__);
		for(int i = 0; i < boxCount; i++) printf("%d:%d ", Endpoints[i].yPos, Endpoints[i].xPos);
		printf("\n");
	}
#endif
	return 0;
}
