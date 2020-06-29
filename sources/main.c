#include "main.h"

int main(int argc, char *argv[])
{
	/* Считывание ip адреса из argv */
	char ipAddr[12];
	if (argc > 1)
	{
		strcpy(ipAddr, argv[1]);
	}
	else
		strcpy(ipAddr, "127.0.0.1");

	/* Блок инициализации ncurses */
	InitCurses();
	/* Окно меню */
	WINDOW *menuWnd = newwin(MENU_ROWS, MENU_COLS, MENU_Y, MENU_X);
	/* Окно игрока */
	WINDOW *lvlWnd = newwin(LVL_WIN_ROWS, LVL_WIN_COLS, MENU_Y, MENU_X);
	/* Окно оппонента */
	WINDOW *lvl2Wnd = newwin(LVL_WIN_ROWS, LVL_WIN_COLS, MENU_Y, MENU_X_OPPONENT);

	/* Счётчик ходов */
	size_t turnCount = 0;

	/* Файл логирования. Для отладочной информации. Перезаписывается при каждом запуске прогарммы */
	FILE *logFile;
	if ((logFile = fopen(LOGFILE, "w")) == NULL)
	{
		printf("'%s': ошибка при открытии лог-файла\n", __FUNCTION__);
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

	/* Инициализация массива уровней */
	int **map = NULL;
	int Levels[LEVEL_COUNT] = {LEVEL_1, LEVEL_2, LEVEL_3};
	bool restart = false;
	init_pair(5, COLOR_WHITE, COLOR_BLUE);

	DrawMenu(menuWnd);

	bool selected = false;
	do
	{
		switch (PickMenu(menuWnd))
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
			MultiPlayer(lvlWnd, lvl2Wnd, map, Player, boxCount, Boxs, endpointCount, Endpoints, logFile, turnCount, restart, Levels, ipAddr);
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
	} while (!selected);

	/* Удаление окон */
	delwin(menuWnd);
	endwin();

	return 0;
}
