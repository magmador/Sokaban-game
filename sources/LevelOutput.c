#include "main.h"

void LevelOutput(WINDOW *lvlWnd, int **map, FILE *logFile, const chtype move, size_t count)
{        	
	lvlWnd = newwin(MAP_ROW_COUNT + 5, MAP_COL_COUNT + 5, MENU_Y, MENU_X); 
	
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
		            wattron(lvlWnd, COLOR_PAIR(1));
		            mvwaddch(lvlWnd, row, col, ACS_BOARD);
		            break;
		        case BOX_MAP_OBJ:
					fprintf(logFile, "%2d ", map[row][col]);
		            wattron(lvlWnd, COLOR_PAIR(2));
		            mvwaddch(lvlWnd, row, col, ACS_BLOCK);
		            break;
		        case ENDPOINT_MAP_OBJ:
					fprintf(logFile, "%2d ", map[row][col]);
		            wattron(lvlWnd, COLOR_PAIR(3));
		            mvwaddch(lvlWnd, row, col, ACS_BULLET);
		            break;
		        case PLAYER_MAP_OBJ:
					fprintf(logFile, "%2d ", map[row][col]);
		            wattron(lvlWnd, COLOR_PAIR(4));
		            mvwaddch(lvlWnd, row, col, move);
		            break;
                default:
                    break;
		    }
		}
		fprintf(logFile, "\n");
	}
	move(MAP_ROW_COUNT + 1, MAP_COL_COUNT - 5);
	printw("R - restart level");
	move(MAP_ROW_COUNT + 2, MAP_COL_COUNT - 5);
	printw("Q - exit");
	move(MAP_ROW_COUNT + 3, MAP_COL_COUNT - 5);
	printw("Counts:%d", count);
	wrefresh(lvlWnd);
	refresh();
}
