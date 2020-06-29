#include "main.h"

void *OpponentReciever(void *arguments)
{
	ArgStruct *args = (ArgStruct *)arguments;
	int len = sizeof(args->addr);
	int **map;
	InitNetBufferMap(&map);
	char buf[NET_BUF_SIZE];
	NetworkBuffer OutBuffer;

	do
	{
		while (recvfrom(args->socket_fd, buf, NET_BUF_SIZE, 0, (struct sockaddr *)&args->addr, &len) == -1)
		{
			fprintf(args->logFile, "Incorrect client recv\n");
		}
		CharToMap(map, &OutBuffer, buf);
		LevelMultiplayerOutput(args->lvl2Wnd, map, args->logFile, UP_MOVE, args->turnCount, args->levelCur + 1);
		sleep(0.5);
	} while (1);
}