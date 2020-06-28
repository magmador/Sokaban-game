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
	WINDOW *lvl2Wnd;
	   
	size_t turnCount = 0;//счетчик ходов - пока здесь
	/* Файл логирования. Для отладочной информации. Перезаписывается при каждом запуске прогарммы */
	FILE *logFile;
	if ((logFile = fopen(LOGFILE, "w")) == NULL)
  	{
    	printf("'%s': ошибка при открытии лог-файла\n", __FUNCTION__);
    	exit(1);
  	}

/* Использовалось для проверки функций. Возможно пригодится */
/* 
    int socket_fd = 0;
    if (!NetworkInit(&socket_fd, server, logFile))
    {
    	fprintf(logFile, "'%s': Can't initialize socket\n", __FUNCTION__);
    	exit(1);
   	}
   	struct sockaddr_in addr;
   	if (!server)
   	{
   		addr.sin_family = AF_INET;
   		addr.sin_port = htons(SERVER_PORT);
   		addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   	}
   	if (!NetworkConnect(&socket_fd, &addr, server, logFile))
    {
    	fprintf(logFile, "'%s': Connection fail!\n", __FUNCTION__);
    	exit(1);
   	}
*/

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
	int Levels[LEVEL_COUNT] = { LEVEL_1, LEVEL_2, LEVEL_3 };
	bool restart = false;
	init_pair(5, COLOR_WHITE, COLOR_BLUE);
	
	DrawMenu(menuWnd); 
	
	bool selected = false;
	do
	{
            switch(PickMenu(menuWnd))
	    {
	        case SINGLE_PLAYER_FLAG:
		{
		   DeleteMenu(menuWnd);
		   selected = true; 
		   SinglePlayer(lvlWnd, map, Player, boxCount, Boxs, endpointCount, Endpoints, logFile, turnCount, restart, Levels);
		   break; 
		}
		case MULTI_PLAYER_FLAG:
		{
		    DeleteMenu(menuWnd);
		    selected = true; 
	            MultiPlayer(lvlWnd, lvl2Wnd, map, Player, boxCount, Boxs, endpointCount, Endpoints, logFile, turnCount, restart, Levels);
		    break; 
		}
		case QUIT_FLAG:
		{
                   DeleteMenu(menuWnd);
		    endwin();
		    selected = true;
		    exit(1); 
		    break; 
		}
		default:
		{
		    break;  
		}      
	    }
	}while(!selected);

	/* Удаление окон */
    delwin(menuWnd);
    endwin();
        
	return 0;
}
