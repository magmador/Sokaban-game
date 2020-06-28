#include "main.h"

void MultiPlayer(WINDOW *lvlWnd, WINDOW *lvl2Wnd, int **map, Object Player, size_t boxCount, Object *Boxs, size_t endpointCount, Object *Endpoints, FILE *logFile, size_t turnCount, bool restart, int Levels[])
{
    DrawMultiplayerMenu();
    bool selected = false;
    do
    {
	    switch(getchar())
	    {
		case 'c':
			selected = true; 
			clear();
			MultiPlayerClient(lvlWnd, lvl2Wnd, map, Player, boxCount, Boxs, endpointCount, Endpoints, logFile, turnCount, restart, Levels);
			break;
		case 's':
			selected = true; 
			clear();
			MultiPlayerServer(lvlWnd, lvl2Wnd, map, Player, boxCount, Boxs, endpointCount, Endpoints, logFile, turnCount, restart, Levels);
			break;
		    default:
		    	break;
		}
	}while(!selected);
}
