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
		for(size_t i = 0; i < boxCount; i++) printf("%d:%d ", Boxs[i].yPos, Boxs[i].xPos);
		printf("\n");
	}
#endif

	size_t endpointCount;
	if(!ObjInit(&endpointCount, &Endpoints, map, ENDPOINT_MAP_OBJ))
	{
		printf("'%s': Can't initialize object Endpoints\n", __FUNCTION__);
		exit(1);
	}
#ifdef DEBUG
	else
	{
		printf("'%s': Object Endpoints successfully initialized\n", __FUNCTION__);
		for(size_t i = 0; i < boxCount; i++) printf("%d:%d ", Endpoints[i].yPos, Endpoints[i].xPos);
		printf("\n");
	}
#endif
	if(!PlayerInit(&Player, map, PLAYER_MAP_OBJ))
	{
		printf("'%s': Can't initialize object Player\n", __FUNCTION__);
		exit(1);
	}
#ifdef DEBUG
	else
	{
		printf("'%s': Object Player successfully initialized\n", __FUNCTION__);
		printf("%d:%d \n", Player.yPos, Player.xPos);
	}
#endif
	if (!PlayerMove("right", map, &Player, boxCount, Boxs, endpointCount, Endpoints))
	{
		printf("'%s': Can't move in selected direction\n", __FUNCTION__);
	}
#ifdef DEBUG
	else
	{
		PlayerMove("up", map, &Player, boxCount, Boxs, endpointCount, Endpoints);
		printf("'%s': Moving right, then up.\n", __FUNCTION__);
		LevelOutput(map);
	}
#endif

	return 0;
}
