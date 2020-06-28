#include "main.h"

bool NetworkConnect(int *socket_fd, struct sockaddr_in *addr, bool server_init, FILE *logFile)
{
	bool connected = false;
	int len = sizeof(*addr);
	char buf[100];
	if (server_init)
	{
		/*Сервер*/
		do
		{
			if (recvfrom(*socket_fd, buf, sizeof(buf), 0, (struct sockaddr *)addr, &len) == -1)
			{
				fprintf(logFile, "Recv request on connection fail!\n");
				return false;
			}
			if (!strcmp(buf, MSG_FROM_CLIENT))
			{
				memcpy((void *)buf, (void *)MSG_TO_CLIENT, sizeof(MSG_TO_CLIENT));
				if (sendto(*socket_fd, buf, sizeof(buf), 0, (struct sockaddr *)addr, len) == -1)
				{
					fprintf(logFile, "Send request on connection fail!\n");
					return false;
				}
				fprintf(logFile, "Connect success!\n");
				connected = true;
				return true;
			}
			else
			{
				fprintf(logFile, "Wrong message from client!\n");
				return false;
			}
		} while (!connected);
	}
	else
	{
		/*Клиент*/
		memcpy((void *)buf, (void *)MSG_FROM_CLIENT, sizeof(MSG_FROM_CLIENT));
		if (sendto(*socket_fd, buf, sizeof(buf), 0, (struct sockaddr *)addr, len) == -1)
		{
			fprintf(logFile, "Send request on connection fail!\n");
			return false;
		}
		do
		{
			if (recvfrom(*socket_fd, buf, sizeof(buf), 0, (struct sockaddr *)addr, &len) == -1)
			{
				fprintf(logFile, "Recv request on connection fail!\n");
				return false;
			}
			if (!strcmp(buf, MSG_TO_CLIENT))
			{
				fprintf(logFile, "Connect success!\n");
				connected = true;
				return true;
			}
		} while (!connected);
	}
}
