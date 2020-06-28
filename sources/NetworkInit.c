#include "main.h"

bool NetworkInit(int *socket_fd, bool server_init, FILE *logFile)
{
	int flags = fcntl(*socket_fd, F_GETFL); 
	fcntl(*socket_fd, F_SETFL, flags | O_NONBLOCK); /* делаем сокет неблокирующим */
	*socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (*socket_fd == -1)
	{
		fprintf(logFile, "Socket initialize fail!\n");
		return false;
	}
	if (server_init)
	{	
		struct sockaddr_in server;
		server.sin_family = AF_INET;
		server.sin_port = htons(SERVER_PORT);
		server.sin_addr.s_addr = INADDR_ANY;
		if (bind(*socket_fd, (struct sockaddr *) &server, sizeof(server)) == -1)
		{
			fprintf(logFile, "Socket bind fail!\n");
			return false;
		}
	}
	return true;
}