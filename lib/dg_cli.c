#include	"unp.h"
#include "errno.h"
void
dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
	int	n;
	char  *sendline = "jm";
	char  recvline[MAXLINE + 1];
        	
	while (1) {
		//printf("sendto before\n");
		Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

		//printf("sendto after\n");
		n = Recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
		if ( n == -1) {
			printf("recv from error %s \n", strerror(errno));
			continue;
		}

		recvline[n] = 0;	/* null terminate */
		Fputs(recvline, stdout);
		break;
	}
}
