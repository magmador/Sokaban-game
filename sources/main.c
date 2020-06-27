#include "main.h"

int main()
{
	/* Блок инициализации ncurses */
	initscr();
        cbreak();
        curs_set(FALSE);
        noecho();
        start_color();
        refresh();

	/* Отрисовка меню */
	WINDOW *menuWnd;
	WINDOW *lvlWnd;
	DrawMenu(menuWnd); 
	PickMenu(menuWnd);
	   
	/* Файл логирования. Для отладочной информации. Перезаписывается при каждом запуске прогарммы */
	FILE *logFile;
	if ((logFile = fopen(LOGFILE, "w")) == NULL)
  	{
    	printf("'%s': ошибка при открытии лог-файла\n", __FUNCTION__);
    	exit(1);
  	}
      
	/* Загрузка уровня */
	int **map = NULL;
	if(!LevelSelect(LEVEL_1, &map))
	{
		fprintf(logFile, "'%s': Level not loaded\n", __FUNCTION__);
		exit(1);
	}
	else
	{
		fprintf(logFile, "'%s': Level successfully loaded\n", __FUNCTION__);
		LevelOutput(lvlWnd, map, logFile, ACS_UARROW);
	}

	/* Инициализация базовых объектов */
	/* Массив ящиков */
	Object *Boxs;
	/* Массив эндпоинтов */
	Object *Endpoints;
	/* Перменная игрока */
	Object Player;

	size_t boxCount;
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

	size_t endpointCount;
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

	getch();

	/* Удаление окон */
        delwin(menuWnd);
        endwin();
        
	return 0;
}
