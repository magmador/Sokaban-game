#include "main.h"

void ObjectInitialization(size_t boxCount, Object *Boxs, FILE *logFile, size_t endpointCount, Object *Endpoints, int **map, Object Player)
{
	if(!ObjInit(&boxCount, &Boxs, map, BOX_MAP_OBJ))
	{
		fprintf(logFile, "'%s': Can't initialize object Boxs\n", __FUNCTION__);
		exit(1);
	}
	else
	{
		fprintf(logFile, "'%s': Object Boxs successfully initialized\n", __FUNCTION__);
		for(size_t i = 0; i < boxCount; i++) fprintf(logFile, "%d:%d ", Boxs[i].yPos, Boxs[i].xPos);
		fprintf(logFile, "\n");
	}
	if(!ObjInit(&endpointCount, &Endpoints, map, ENDPOINT_MAP_OBJ))
	{
		fprintf(logFile, "'%s': Can't initialize object Endpoints\n", __FUNCTION__);
		exit(1);
	}
	else
	{
		fprintf(logFile, "'%s': Object Endpoints successfully initialized\n", __FUNCTION__);
		for(size_t i = 0; i < boxCount; i++) fprintf(logFile, "%d:%d ", Endpoints[i].yPos, Endpoints[i].xPos);
		fprintf(logFile, "\n");
	}
	if(!PlayerInit(&Player, map, PLAYER_MAP_OBJ))
	{
		fprintf(logFile, "'%s': Can't initialize object Player\n", __FUNCTION__);
		exit(1);
	}
	else
	{
		fprintf(logFile, "'%s': Object Player successfully initialized\n", __FUNCTION__);
		fprintf(logFile, "%d:%d \n", Player.yPos, Player.xPos);
	}
}