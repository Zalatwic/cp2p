#include "HeartbeatPing.h"
#include "SCon.h"
#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

std::list<SCon> ipStow;
bool classActive = false;
bool classTerminal = false;

int main() {
	//timeout if three failed attempts
	std::list<int> retryLis;
	for(int buildRetry = 0; buildRetry < ipStow.size(); buildRetry++) {
		retryLis.push_back(0);
	}

	int inSock, inConnect;
	struct addrinfo hints, *servinfo, *p;
	struct sockaddr_storage ipIn;
	socklen_t sin_size;
	struct sigaction sa;
	int yes = 1;
	char s[INET6_ADDRSTRLEN];
	int rv;

	memset(&hints, 0, sizeof hints);
	ints.ai_family =AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if((rv = getaddrinfo(NULL, HPORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	for(p = servinfo; p != NULL; p = p->ai_next) {
		if((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("server: socket");
			continue;
		}

		if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
			perror("setsockopt");
			exit(1);
		}

		if(bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("server: bind");
			continue;
		}

		break;
	}

	freeaddrinfo(servinfo);

	if(p == NULL) {
		fprintf(stderr, "but nobody came\n");
		exit(1);
	}

	if(listen(sockfd, BACKLOG) == -1) {
		perror("listening");
		exit(1);
	}
	
	sa.sa_handler = sigchld_handler; //clear up irrelevant processess
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if(sigaction(SIGCHLD, &sa, NULL) == -1) {
			perror("sigaction");
			exit(1);
	}

	printf("Waiting for recessitation");

	//wait until system activates the class
	while(classActive == false);

	//loop until the user issues a hit
	while(classActive == true) {
		sin_size = sizeof ipIn;
		new_fd = accept(sockfd, (struct sockaddr *)&ipIn, &sin_size);
		
		if(new_fd == -1) {
			perror("accept");
			continue;
		}

		inet_ntop(ipIn.ss_family, get_in_addr((struct socketaddr *)&ipIn), s, sizeof s);
		printf("%s has connected\n", s);

		if(!fork()) {
			close(sockfd);
			
			if(send(new_fd, "peace on earth", 13, 0) == -1) {
				perror("send");
			}

			close(new_fd);
			exit(0);
		}
		
		close(new_fd);
	}

	classTerminal = false;
}

void startClass() {
	classActive = true;
}

void stopClass() {
	classActive = false;
}

bool isClassTerminal() {
	return classTerminal;
}

HeartbeatPing(std::list<SCon> ipList) {
	ipStow = ipList;
}
