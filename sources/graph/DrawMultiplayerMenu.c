#include "main.h"

void DrawMultiplayerMenu(WINDOW *multiWnd)
{
    /* Две цветовых пары для самого окна и шрифта для удобства измения цветов */
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);

    wbkgd(multiWnd, COLOR_PAIR(1));
    wattron(multiWnd, A_BOLD);

    wattron(multiWnd, COLOR_PAIR(2));
    mvwprintw(multiWnd, MULTI_MENU_ROWS / 2 - 2, 1, MULTI_MENU_TITLE);
    mvwprintw(multiWnd, MULTI_MENU_ROWS / 2 - 1, 1, MULTI_MENU_CLIENT);
    mvwprintw(multiWnd, MULTI_MENU_ROWS / 2, 1, MULTI_MENU_SERVER);
    wattroff(multiWnd, COLOR_PAIR(2));

    box(multiWnd, 0, 0);
    wrefresh(multiWnd);
    refresh();
}
