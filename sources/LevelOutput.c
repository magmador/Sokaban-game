#include "main.h"

void LevelOutput(WINDOW *lvlWnd, int **map, FILE *logFile, const chtype move)
{        
        lvlWnd = newwin(MAP_ROW_COUNT, MAP_COL_COUNT, MENU_Y, MENU_X);
        
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(3, COLOR_RED, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        
	for(size_t row = 0; row < MAP_ROW_COUNT; row++)
	{
		for(size_t col = 0; col < MAP_COL_COUNT; col++)
		{
		        switch(map[row][col])
		        {
		            case -1:
		                continue;
		                break;
		            case 0:
		                continue;
		                break;
		            case 1:
		                wattron(lvlWnd, COLOR_PAIR(1));
		                mvwaddch(lvlWnd, row, col, ACS_BOARD);
		                break;
		            case 2:
		                wattron(lvlWnd, COLOR_PAIR(2));
		                mvwaddch(lvlWnd, row, col, ACS_BLOCK);
		                break;
		            case 3:
		                wattron(lvlWnd, COLOR_PAIR(3));
		                mvwaddch(lvlWnd, row, col, ACS_BULLET);
		                break;
		            case 4:
		                wattron(lvlWnd, COLOR_PAIR(4));
		                mvwaddch(lvlWnd, row, col, move);
		                break;
                           default:
                                break;
		        }
		        wrefresh(lvlWnd);
	                refresh();
			fprintf(logFile, "%2d ", map[row][col]);
		}
		fprintf(logFile, "\n");
	}
}
