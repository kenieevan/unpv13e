#include	"unp.h"

int
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;
	struct sockaddr_in	srcaddr;

	if (argc != 3)
		err_quit("usage: udpcli <IPaddress> <port>");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);


	bzero(&srcaddr, sizeof(srcaddr));
	srcaddr.sin_family = AF_INET;
	srcaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	srcaddr.sin_port = htons(atoi(argv[2]));


	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	if (bind(sockfd, (struct sockaddr *) &srcaddr, sizeof(srcaddr)) < 0) {
		perror("bind");
		exit(1);
	}
	dg_cli(stdin, sockfd, (SA *) &servaddr, sizeof(servaddr));

	exit(0);
}
