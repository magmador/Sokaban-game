#include "main.h"

void DrawMenu(WINDOW *menuWnd)
{
    menuWnd = newwin(MENU_ROWS, MENU_COLS, MENU_Y, MENU_X);

    /* Две цветовых пары для самого окна и шрифта для удобства измения цветов */
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);

    wbkgd(menuWnd, COLOR_PAIR(1));
	wattron(menuWnd, A_BOLD);

    wattron(menuWnd, COLOR_PAIR(2));
    mvwprintw(menuWnd, MENU_ROWS/2 - 3, (MENU_COLS/2 - strlen(MENU_TITLE)/2), MENU_TITLE);
    mvwprintw(menuWnd, MENU_ROWS/2 - 2, (MENU_COLS/2 - strlen(MENU_SIN)/2), MENU_SIN);
    mvwprintw(menuWnd, MENU_ROWS/2 - 1, (MENU_COLS/2 - strlen(MENU_MULTI)/2), MENU_MULTI);
    mvwprintw(menuWnd, MENU_ROWS/2, (MENU_COLS/2 - strlen(MENU_EXIT)/2), MENU_EXIT);
    wattroff(menuWnd, COLOR_PAIR(2));

	box(menuWnd, 0, 0);
	wrefresh(menuWnd);
	refresh();
}
