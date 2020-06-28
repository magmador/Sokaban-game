#include "main.h"

void InitCurses()
{
    initscr();
    cbreak();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    refresh();
}
