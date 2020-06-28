#include "main.h"

void MultiPlayer(WINDOW *lvlWnd, WINDOW *lvl2Wnd, int **map, Object Player, size_t boxCount, Object *Boxs, size_t endpointCount, Object *Endpoints, FILE *logFile, size_t turnCount, bool restart, int Levels[])
{
	DrawMultiplayerMenu();
	int socket_fd = 0;
	struct sockaddr_in addr;
	bool selected = false;
	do
	{
		switch (getchar())
		{
		case 'c':
			selected = true;
			clear();
			/*if (!NetworkInit(&socket_fd, 0, logFile))
    			{
    				fprintf(logFile, "'%s': Can't initialize socket\n", __FUNCTION__);
    				exit(1);
   			}

		   	addr.sin_family = AF_INET;
		   	addr.sin_port = htons(SERVER_PORT);
		   	addr.sin_addr.s_addr = inet_addr("127.0.0.1");*/

			MultiPlayerClient(&socket_fd, &addr, lvlWnd, lvl2Wnd, map, Player, boxCount, Boxs, endpointCount, Endpoints, logFile, turnCount, restart, Levels);
			break;
		case 's':
			selected = true;
			clear();
			/*if (!NetworkInit(&socket_fd, 1, logFile))
    			{
    				fprintf(logFile, "'%s': Can't initialize socket\n", __FUNCTION__);
    				exit(1);
   			}*/
			MultiPlayerServer(&socket_fd, &addr, lvlWnd, lvl2Wnd, map, Player, boxCount, Boxs, endpointCount, Endpoints, logFile, turnCount, restart, Levels);
			break;
		default:
			break;
		}
	} while (!selected);
}
