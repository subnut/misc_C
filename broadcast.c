#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>	// man 7 ip

/*
 * stdio.h	- printf(), fprintf(), fputs()
 * stdlib.h	- EXIT_FAILURE
 * string.h	- strlen()
 * arpa/inet.h	- htonl()
 * sys/socket.h	- socket(), setsockopt()
 * netinet/in.h	- sockaddr_in, in_port_t, INADDR_BROADCAST
 */

int
main(void)
{
	/* Create the socket */
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	/* Allow the socket to send broadcast messages */
	int option_value = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &option_value, sizeof option_value) != 0)
		return perror("setsockopt error"),
		       EXIT_FAILURE;

	/* Send the message */
	char *message = "Howdy?";
	struct sockaddr_in address;
	address.sin_port = (in_port_t)htons(5000);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_BROADCAST);
#include <unistd.h>
	while (sleep(1), 1)
	if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&address, sizeof address) == -1)
		return perror("sendto failed"),
		       EXIT_FAILURE;

	return 0;
}
