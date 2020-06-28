#include "main.h"

int main()
{
	/* Блок инициализации ncurses */
	initscr();
    cbreak();
    curs_set(FALSE);
	keypad(stdscr, TRUE);
    noecho();
    start_color();
    refresh();

	/* Отрисовка меню */
	WINDOW *menuWnd;
	WINDOW *lvlWnd;
//	DrawMenu(menuWnd); 
//	PickMenu(menuWnd);

	   
	size_t turnCount = 0;//счетчик ходов - пока здесь
	/* Файл логирования. Для отладочной информации. Перезаписывается при каждом запуске прогарммы */
	FILE *logFile;
	if ((logFile = fopen(LOGFILE, "w")) == NULL)
  	{
    	printf("'%s': ошибка при открытии лог-файла\n", __FUNCTION__);
    	exit(1);
  	}
 
    int socket_fd = 0;
    if (!NetworkInit(&socket_fd, true, logFile))
    {
    	fprintf(logFile, "'%s': Can't initialize socket\n", __FUNCTION__);
    	exit(1);
   	}     

	/* Инициализация базовых объектов */
	/* Массив ящиков */
	Object *Boxs;
	/* Массив эндпоинтов */
	Object *Endpoints;
	/* Перменная игрока */
	Object Player;
	/* Количество ящиков и эндпоинтов*/
	size_t boxCount, endpointCount;

	/* Загрузка уровня */
	int **map = NULL;
	int Levels[] = { LEVEL_1, LEVEL_2, LEVEL_3 };
	bool restart = false;
	init_pair(5, COLOR_WHITE, COLOR_BLUE);
	for(int levelCur = 0; levelCur < (sizeof(Levels)/sizeof(int)); levelCur++)
	{
		ObjectInitialization(&boxCount, &Boxs, logFile, &endpointCount, &Endpoints, &map, &Player, Levels[levelCur], &turnCount);	
		LevelOutput(lvlWnd, map, logFile, UP_MOVE, turnCount);

		do
		{
			if(PlayerMove(lvlWnd, map, &Player, boxCount, Boxs, endpointCount, Endpoints, logFile, &turnCount, &restart)) 
			{
				attron(COLOR_PAIR(5));
				mvwprintw(stdscr,MAP_ROW_COUNT + 4, MAP_COL_COUNT - 4, LVL_CLEAR);
				break;
			}
			if(restart)
			{
				ObjectInitialization(&boxCount, &Boxs, logFile, &endpointCount, &Endpoints, &map, &Player, Levels[levelCur], &turnCount);
				LevelOutput(lvlWnd, map, logFile, UP_MOVE, turnCount);
				restart = false;
			}
		}while(1);

		attron(COLOR_PAIR(5));
		mvwprintw(stdscr,MAP_ROW_COUNT + 5, MAP_COL_COUNT - 4, PRESS_KEY);
		refresh();
		getch();
	}

	/* Удаление окон */
    delwin(menuWnd);
    endwin();
        
	return 0;
}
