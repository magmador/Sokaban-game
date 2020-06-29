#include "main.h"

void LevelEndSend(int *socket_fd, struct sockaddr_in *addr, FILE *logFile)
{
	int len = sizeof(*addr);
	if (sendto(*socket_fd, MSG_LVL_END, sizeof(MSG_LVL_END), 0, (struct sockaddr *) addr, len) == -1)
	{
		fprintf(logFile, "Incorrect client send\n");
	    exit(1);
	}
}