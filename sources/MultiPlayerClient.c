#include "main.h"

void MultiPlayerClient(int *socket_fd, struct sockaddr_in *addr, WINDOW *lvlWnd, WINDOW *lvl2Wnd, int **map, Object Player, size_t boxCount, Object *Boxs, size_t endpointCount, Object *Endpoints, FILE *logFile, size_t turnCount, bool restart, int Levels[])
{
	int len = sizeof(*addr);
	NetworkBuffer InBuffer;
	InitNetBufferMap(&InBuffer.map);
	NetworkBuffer OutBuffer;
	InitNetBufferMap(&OutBuffer.map);
	
	for (int levelCur = 0; levelCur < LEVEL_COUNT; levelCur++)
	{
		ObjectInitialization(&boxCount, &Boxs, logFile, &endpointCount, &Endpoints, &map, &Player, Levels[levelCur], &turnCount);

		memcpy(InBuffer.map, map, MAP_SIZE);

		LevelOutput(lvlWnd, map, logFile, UP_MOVE, turnCount, levelCur + 1);
		if(sendto(*socket_fd, InBuffer.map, MAP_SIZE, 0, (struct sockaddr *) addr, len) == -1)
		{
			fprintf(logFile, "Incorrect client send\n");
		    exit(1);
		}
		if(recvfrom(*socket_fd, OutBuffer.map, MAP_SIZE, 0, (struct sockaddr *) addr, &len) == -1)
		{
			fprintf(logFile, "Incorrect client recv\n");
		    exit(1);
		}
		LevelMultiplayerOutput(lvl2Wnd, OutBuffer.map, logFile, UP_MOVE, turnCount, levelCur + 1);
		do
		{
			if (PlayerMove(lvlWnd, map, &Player, boxCount, Boxs, endpointCount, Endpoints, logFile, &turnCount, &restart, levelCur))
			{
				attron(COLOR_PAIR(5));
				mvwprintw(stdscr, MAP_ROW_COUNT + 4, MAP_COL_COUNT - 4, LVL_CLEAR);
				break;
			}
			if (restart)
			{
				ObjectInitialization(&boxCount, &Boxs, logFile, &endpointCount, &Endpoints, &map, &Player, Levels[levelCur], &turnCount);
				LevelOutput(lvlWnd, map, logFile, UP_MOVE, turnCount, levelCur + 1);
				restart = false;
			}
		} while (1);

		attron(COLOR_PAIR(5));
		mvwprintw(stdscr, MAP_ROW_COUNT + 5, MAP_COL_COUNT - 4, PRESS_KEY);
		refresh();
		getch();
	}
}
