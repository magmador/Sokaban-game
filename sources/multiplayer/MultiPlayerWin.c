#include "main.h"

void MultiPlayerWin(size_t turnCountMIne, size_t turnCountOp)
{
		if(turnCountMIne < turnCountOp)
		{
            mvwprintw(stdscr, MAP_ROW_COUNT + 5, MAP_COL_COUNT - 4, "                ");
			mvwprintw(stdscr, MAP_ROW_COUNT + 5, MAP_COL_COUNT - 4, MULTIPLAYER_WON);
			refresh();
			mvwprintw(stdscr, MAP_ROW_COUNT + 5, MENU_X_OPPONENT + 1, MULTIPLAYER_LOST);
		}
		else if(turnCountMIne == turnCountOp)
		{
            mvwprintw(stdscr, MAP_ROW_COUNT + 5, MAP_COL_COUNT - 4, "                ");
			mvwprintw(stdscr, MAP_ROW_COUNT + 5, MAP_COL_COUNT - 4, MULTIPLAYER_DRAW);
			refresh();
			mvwprintw(stdscr, MAP_ROW_COUNT + 5, MENU_X_OPPONENT + 1, MULTIPLAYER_DRAW);
		}
		else
		{
            mvwprintw(stdscr, MAP_ROW_COUNT + 5, MAP_COL_COUNT - 4, "                ");
			mvwprintw(stdscr, MAP_ROW_COUNT + 5, MAP_COL_COUNT - 4, MULTIPLAYER_LOST);
			refresh();
			mvwprintw(stdscr, MAP_ROW_COUNT + 5, MENU_X_OPPONENT + 1, MULTIPLAYER_WON);
		}
		
		refresh();
		sleep(3);
}