#include "main.h"

void LevelMultiplayerOutput(WINDOW *lvl2Wnd, int **map, FILE *logFile, const chtype move, size_t count, size_t levelCur)
{
	//refresh();
	lvl2Wnd = newwin(LVL_WIN_ROWS, LVL_WIN_COLS, MENU_Y, MENU_X_OPPONENT);
	wattron(lvl2Wnd, A_BOLD);
	box(lvl2Wnd, 0, 0);

	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(3, COLOR_RED, COLOR_BLUE);
	init_pair(4, COLOR_BLACK, COLOR_BLUE);
	init_pair(5, COLOR_WHITE, COLOR_BLUE);

	wbkgd(lvl2Wnd, COLOR_PAIR(5));

	for (size_t row = 0; row < MAP_ROW_COUNT; row++)
	{
		for (size_t col = 0; col < MAP_COL_COUNT; col++)
		{
			switch (map[row][col])
			{
			case NOT_PL_SPACE_MAP_OBJ:
				fprintf(logFile, "%2d ", map[row][col]);
				continue;
				break;
			case SPACE_MAP_OBJ:
				fprintf(logFile, "%2d ", map[row][col]);
				continue;
				break;
			case WALL_MAP_OBJ:
				fprintf(logFile, "%2d ", map[row][col]);
				wattron(lvl2Wnd, COLOR_PAIR(1));
				mvwaddch(lvl2Wnd, row - 1, col + 5, ACS_BOARD);
				break;
			case BOX_MAP_OBJ:
				fprintf(logFile, "%2d ", map[row][col]);
				wattron(lvl2Wnd, COLOR_PAIR(2));
				mvwaddch(lvl2Wnd, row - 1, col + 5, ACS_BLOCK);
				break;
			case ENDPOINT_MAP_OBJ:
				fprintf(logFile, "%2d ", map[row][col]);
				wattron(lvl2Wnd, COLOR_PAIR(3));
				mvwaddch(lvl2Wnd, row - 1, col + 5, ACS_BULLET);
				break;
			case PLAYER_MAP_OBJ:
				fprintf(logFile, "%2d ", map[row][col]);
				wattron(lvl2Wnd, COLOR_PAIR(4));
				mvwaddch(lvl2Wnd, row - 1, col + 5, move);
				break;
			default:
				break;
			}
		}
		fprintf(logFile, "\n");
	}
	fprintf(logFile, "\n");

	attron(COLOR_PAIR(5));
	move(MAP_ROW_COUNT + 1, MENU_X_OPPONENT + 6);
	printw("Opponent");
	move(MAP_ROW_COUNT + 2, MENU_X_OPPONENT + 6);
	printw("Level %d", levelCur);
	move(MAP_ROW_COUNT + 3, MENU_X_OPPONENT + 6);
	printw("Turns:%d", count);
	wrefresh(lvl2Wnd);
	refresh();
}
