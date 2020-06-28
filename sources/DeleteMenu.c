#include "main.h"

void DeleteMenu(WINDOW *menuWnd)
{
    delwin(menuWnd);
    clear();
    refresh();
}
