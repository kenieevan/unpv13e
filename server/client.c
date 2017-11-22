#include	"unp.h"

#define	MAXN	16384		/* max # bytes to request from server */
#include <unistd.h>
int
main(int argc, char **argv)
{
	int		i, j, fd, nchildren, nsleep;
	int forked = 0;
	pid_t	pid;
	ssize_t	n;
	char	request[MAXLINE], reply[MAXN];

	if (argc != 5)
		err_quit("usage: client <hostname or IPaddr> <port> <#children> "
				 "sleep secs");

	nchildren = atoi(argv[3]);
	nsleep = atoi(argv[4]);

	for (i = 0; i < nchildren; i++) {
	        printf("%d \n", forked++);
		if ( (pid = Fork()) == 0) {		/* child */
			fd = Tcp_connect(argv[1], argv[2]);
			
		//	for (j = 0; j < nloops; j++) {
		//		Write(fd, request, strlen(request));
		//		if ( (n = Readn(fd, reply, nbytes)) != nbytes)
		//			err_quit("server returned %d bytes", n);
		//	}
		//
			sleep(nsleep);
			Close(fd);		/* TIME_WAIT on client, not server */
			printf("child %d done\n", i);
			exit(0);
		}
		/* parent loops around to fork() again */
	}

	while (wait(NULL) > 0)	/* now parent waits for all children */
		;
	if (errno != ECHILD)
		err_sys("wait error");

	exit(0);
}
