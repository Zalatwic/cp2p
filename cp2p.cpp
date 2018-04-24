//cp2p server
//
//kevin szmyd [kps59]
//lucas invernizzi [lmi12]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT	5833

void error(const char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]) {
	//set variables for creation of server
	int inSock, outSock;
	socklen_t clilen;
	char buffer[1024];
	struct sockaddr_in ipHere, ipThere;
	int x;
		
	inSock = socket(AF_INET, SOCK_STREAM, 0);
	if(inSock < 0) {
		error("gunstock");
	}

	bzero((char *) &ipHere, sizeof(ipHere));
	
	//set simple parameters 
	ipHere.sin_family = AF_INET;
	ipHere.sin_addr.s_addr = INADDR_ANY;
	ipHere.sin_port = PORT;

	if(bind(inSock, (struct sockaddr *) &ipHere, sizeof(ipHere)) < 0) {
		error("ekans");
	}

	//create a socket to listen
	listen(inSock, 5);
	clilen = sizeof(ipThere);

	outSock = accept(inSock, (struct sockaddr *) &ipThere, &clilen);
	if(inSock < 0) {
		error("chris");
	}

	bzero(buffer, 1024);
	x = read(outSock, buffer, 1023);
	if(x < 0) {
		error("flick");
	}

	//print the buffer and send a responce
	printf("%s", buffer);

	x = write(outSock, "recieved", 18);

	close(inSock);
	close(outSock);

	return 0;
}
