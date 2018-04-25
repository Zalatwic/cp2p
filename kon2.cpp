//kon2 client
//
//kevin szmyd [kps59]
//lucas invernizzi [lmi12]

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT	5833

using namespace std;

int main(int argc, char *argv[]) {
	std::cout<<"a";
	//set variables for the pass to server
	int mainSock, x;
	struct sockaddr_in ipThere;
	struct hostent *server;
	std::cout<<"b";
	char buffer[1024];
	
	mainSock = socket(AF_INET, SOCK_STREAM, 0);
	if(mainSock < 0) {
		std::cout << "couldn't creat socket" << std::endl;
	}

	server = gethostbyname(argv[1]);
	if(server == NULL) {
		std::cout << "couldn't get host" << std::endl;
	}
	std::cout << server << std::endl;
	bzero((char *) &ipThere, sizeof(ipThere));
	ipThere.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&ipThere.sin_addr.s_addr, server->h_length);
	ipThere.sin_port = htons(PORT);
	if(connect(mainSock, (struct sockaddr *) &ipThere, sizeof(ipThere)) < 0) {
		std::cout << "couldn't send message" << std::endl;
	}

	printf("\n: ");
	bzero(buffer, 1024);
	fgets(buffer, 1023, stdin);
	x = write(mainSock, buffer, strlen(buffer));
	bzero(buffer, 1024);
	x = read(mainSock, buffer, 1023);
	printf("%s\n", buffer);
	
	close(mainSock);
	return 0;
}
