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
		if(recvfrom(args->socket_fd, buf, NET_BUF_SIZE, 0, (struct sockaddr *)&args->addr, &len) == -1)
		{
			fprintf(args->logFile, "Incorrect client recv\n");
		}

		if(!strcmp(buf, MSG_LVL_END))
		{
			break;
		}
		
		CharToMap(map, &OutBuffer, buf);
		args->turnCount = OutBuffer.turnCount;
		LevelMultiplayerOutput(args->lvl2Wnd, map, args->logFile, OutBuffer.move, args->turnCount, args->levelCur + 1);
		sleep(0.5);
	} while (1);
	pthread_exit(NULL);
}