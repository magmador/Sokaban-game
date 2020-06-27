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
	DrawMenu(menuWnd); 
	PickMenu(menuWnd);

	   
	size_t turnCount = 0;//счетчик ходов - пока здесь
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
		LevelOutput(lvlWnd, map, logFile, UP_MOVE, turnCount);
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
	ObjectInitialization(&boxCount, &Boxs, logFile, &endpointCount, &Endpoints, map, &Player);	

	bool restart = false;
	do
	{
		if(PlayerMove(lvlWnd, map, &Player, boxCount, Boxs, endpointCount, Endpoints, logFile, &turnCount, &restart)) 
		{
			printf("WIN"); 
			break;
		}
		if(restart)
		{
			if(!LevelSelect(LEVEL_1, &map))
			{
				fprintf(logFile, "'%s': Level not loaded\n", __FUNCTION__);
				exit(1);
			}
			else
			{
				fprintf(logFile, "'%s': Level successfully loaded\n", __FUNCTION__);
				LevelOutput(lvlWnd, map, logFile, UP_MOVE, turnCount);
			}
			ObjectInitialization(&boxCount, &Boxs, logFile, &endpointCount, &Endpoints, map, &Player);
			LevelOutput(lvlWnd, map, logFile, UP_MOVE, turnCount);
			restart = false;
		}
	}while(1);

	/* Удаление окон */
	getch();
    delwin(menuWnd);
    endwin();
        
	return 0;
}
