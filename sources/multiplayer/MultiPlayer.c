#include "main.h"

void MultiPlayer(WINDOW *lvlWnd, WINDOW *lvl2Wnd, int **map, Object Player, size_t boxCount, Object *Boxs, size_t endpointCount, Object *Endpoints, FILE *logFile, size_t turnCount, bool restart, int Levels[], char *ipAddr)
{
	WINDOW *multiWnd = newwin(MULTI_MENU_ROWS, MULTI_MENU_COLS, MULTI_MENU_Y, MULTI_MENU_X);
	DrawMultiplayerMenu(multiWnd);
	int socket_fd = 0;
	struct sockaddr_in addr;
	bool selected = false;
	do
	{
		switch (getchar())
		{
		case 'c':
			selected = true;
			erase();
			if (!NetworkInit(&socket_fd, 0, logFile))
			{
				fprintf(logFile, "'%s': Can't initialize socket\n", __FUNCTION__);
				exit(1);
			}

			addr.sin_family = AF_INET;
			addr.sin_port = htons(SERVER_PORT);
			addr.sin_addr.s_addr = inet_addr(ipAddr);

			if (!NetworkConnect(&socket_fd, &addr, 0, logFile))
			{
				fprintf(logFile, "'%s': Connection fail!\n", __FUNCTION__);
				exit(1);
			}
			delwin(multiWnd);
			MultiPlayerClient(&socket_fd, &addr, lvlWnd, lvl2Wnd, map, Player, boxCount, Boxs, endpointCount, Endpoints, logFile, turnCount, restart, Levels);
			break;
		case 's':
			selected = true;
			erase();
			if (!NetworkInit(&socket_fd, 1, logFile))
			{
				fprintf(logFile, "'%s': Can't initialize socket\n", __FUNCTION__);
				exit(1);
			}

			if (!NetworkConnect(&socket_fd, &addr, 1, logFile))
			{
				fprintf(logFile, "'%s': Connection fail!\n", __FUNCTION__);
				exit(1);
			}
			delwin(multiWnd);
			MultiPlayerServer(&socket_fd, &addr, lvlWnd, lvl2Wnd, map, Player, boxCount, Boxs, endpointCount, Endpoints, logFile, turnCount, restart, Levels);
			break;
		default:
			break;
		}
	} while (!selected);
}
