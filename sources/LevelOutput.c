#include "main.h"

void LevelOutput(WINDOW *lvlWnd, int **map, FILE *logFile, const chtype move, size_t count)
{        	
    refresh();
    lvlWnd = newwin(LVL_WIN_ROWS, LVL_WIN_COLS, MENU_Y, MENU_X);
    wattron(lvlWnd, A_BOLD);
    box(lvlWnd,0,0);

    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_MAGENTA, COLOR_BLUE);
    init_pair(3, COLOR_RED, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_BLUE);
	init_pair(5, COLOR_WHITE, COLOR_BLUE);

	wbkgd(lvlWnd, COLOR_PAIR(5));
        
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
		            mvwaddch(lvlWnd, row - 1, col + 5, ACS_BOARD);
		            break;
		        case BOX_MAP_OBJ:
					fprintf(logFile, "%2d ", map[row][col]);
		            wattron(lvlWnd, COLOR_PAIR(2));
		            mvwaddch(lvlWnd, row - 1, col + 5, ACS_BLOCK);
		            break;
		        case ENDPOINT_MAP_OBJ:
					fprintf(logFile, "%2d ", map[row][col]);
		            wattron(lvlWnd, COLOR_PAIR(3));
		            mvwaddch(lvlWnd, row - 1, col + 5, ACS_BULLET);
		            break;
		        case PLAYER_MAP_OBJ:
					fprintf(logFile, "%2d ", map[row][col]);
		            wattron(lvlWnd, COLOR_PAIR(4));
		            mvwaddch(lvlWnd, row - 1, col + 5, move);
		            break;
                default:
                    break;
		    }
		}
		fprintf(logFile, "\n");
	}
	fprintf(logFile, "\n");

	attron(COLOR_PAIR(5));
	move(MAP_ROW_COUNT + 1, MAP_COL_COUNT - 4);
	printw("You");
	move(MAP_ROW_COUNT + 2, MAP_COL_COUNT - 4);
	printw("R - restart level!");
	move(MAP_ROW_COUNT + 3, MAP_COL_COUNT - 4);
	printw("Q - exit!");
	move(MAP_ROW_COUNT + 4, MAP_COL_COUNT - 4);
	printw("Turns:%d", count);
	wrefresh(lvlWnd);
	refresh();
}
