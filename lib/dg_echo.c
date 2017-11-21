#include	"unp.h"
int count = 0;
void
dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen)
{
	int			n;
	socklen_t	len;
	char		mesg[MAXLINE];

	for ( ; ; ) {
		len = clilen;
		n = Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
                count++;
                printf("count is %d\n", count);

		Sendto(sockfd, mesg, n, 0, pcliaddr, len);
	}
}
