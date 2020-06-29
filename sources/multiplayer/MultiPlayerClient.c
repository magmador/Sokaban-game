#include "main.h"

void MultiPlayerClient(int *socket_fd, struct sockaddr_in *addr, WINDOW *lvlWnd, WINDOW *lvl2Wnd, int **map, Object Player, size_t boxCount, Object *Boxs, size_t endpointCount, Object *Endpoints, FILE *logFile, size_t turnCount, bool restart, int Levels[])
{
	int len = sizeof(*addr);
	NetworkBuffer InBuffer;

	char buf[NET_BUF_SIZE];
	pthread_t recieverThread;
	ArgStruct args;
	args.socket_fd = *socket_fd;
	memcpy(&args.addr, addr, sizeof(struct sockaddr_in));
	args.lvl2Wnd = lvl2Wnd;
	args.logFile = logFile;
	args.turnCount = turnCount;

	for (int levelCur = 0; levelCur < LEVEL_COUNT; levelCur++)
	{
		ObjectInitialization(&boxCount, &Boxs, logFile, &endpointCount, &Endpoints, &map, &Player, Levels[levelCur], &turnCount);
		LevelOutput(lvlWnd, map, logFile, UP_MOVE, turnCount, levelCur + 1);
		args.levelCur = levelCur;
		pthread_create(&recieverThread, NULL, (void *) OpponentReciever, (void *) &args);

		InBuffer.move = UP_MOVE;
		InBuffer.turnCount = turnCount;
		MapToChar(map, &InBuffer, buf);
		if (sendto(*socket_fd, buf, NET_BUF_SIZE, 0, (struct sockaddr *) addr, len) == -1)
		{
			fprintf(logFile, "Incorrect client send\n");
		    exit(1);
		}
		
		do
		{
			if (MultiPlayerMove(lvlWnd, map, &Player, boxCount, Boxs, endpointCount, Endpoints, logFile, &turnCount, &restart, levelCur, &InBuffer, buf, socket_fd, addr))
			{
				attron(COLOR_PAIR(5));
				mvwprintw(stdscr, MAP_ROW_COUNT + 4, MAP_COL_COUNT - 4, LVL_CLEAR);
				LevelEndSend(socket_fd, addr, logFile);
				break;
			}
			if (restart)
			{
				ObjectInitialization(&boxCount, &Boxs, logFile, &endpointCount, &Endpoints, &map, &Player, Levels[levelCur], &turnCount);
				LevelOutput(lvlWnd, map, logFile, UP_MOVE, turnCount, levelCur + 1);
				restart = false;

				InBuffer.move = UP_MOVE;
				InBuffer.turnCount = turnCount;
				MapToChar(map, &InBuffer, buf);
				if (sendto(*socket_fd, buf, NET_BUF_SIZE, 0, (struct sockaddr *) addr, len) == -1)
				{
					fprintf(logFile, "Incorrect server send\n");
					exit(1);
				}
			}
		} while (1);

		attron(COLOR_PAIR(5));
		mvwprintw(stdscr, MAP_ROW_COUNT + 5, MAP_COL_COUNT - 4, WAIT_OPPONENT);
		refresh();
		pthread_join(recieverThread, NULL);

		MultiPlayerWin(turnCount, args.turnCount);

		CleanStdin();
	}
}
