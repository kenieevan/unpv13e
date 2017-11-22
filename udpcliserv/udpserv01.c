#include	"unp.h"

int
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr, cliaddr;
	unsigned int srcaddr;
	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
	char *host = argv[1];
	if (argc != 2) {
		printf("input host addr to bind\n");
		return -1;
	}

	inet_pton(AF_INET, host, &srcaddr);
	printf("src addr net order is %x\n", srcaddr);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = srcaddr;
	servaddr.sin_port        = htons(SERV_PORT);

	Bind(sockfd, (SA *) &servaddr, sizeof(servaddr));

	dg_echo(sockfd, (SA *) &cliaddr, sizeof(cliaddr));
}
