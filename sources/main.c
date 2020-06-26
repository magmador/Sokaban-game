#include "main.h"

Object *Boxs; //массив ящиков
Object *Endpoints; //массив эндпоинтов
Object Player; //перменная игрока

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
