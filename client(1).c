#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>    
#include<sys/socket.h> 
#include<arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include "color.h" // color red for fail, green for authenticated message.

char pass[10];


void halt(void) 
{
	while(1)
	{

	}
}


int main(int argc, char *argv[])
{
	struct timeval tv1, tv2;
	int malicious = 0;
	struct timeval tv = { 2, 0};

	if(argc != 2) {
		printf("Usage error: ./client.out [password]!\n");
		return (-1);
	}

	strcpy(pass, argv[1]);

	if(strcmp("666",pass) == 0)
		malicious++;

	int sock;
	struct sockaddr_in server;
	char message[1000], server_reply[2000];

	//Create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == -1)
	{
		printf("Could not create socket");
	}
	puts("Socket created");

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 3222);

	//Connect to remote server
	if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("connect failed. Error");
		return 1;
	}

	puts("\tConnected\n");
	
//	scanf("%s", message);
	strcpy(message, pass);

	if( send(sock, message, strlen(message), 0) < 0) {
		puts("Send failed");
		return 1;
	}

	printf("Send to Kernel module: %s\n", message);

	
	// halt();	pause execution.

	char buffer[200];
	int nbytes;

	memset(buffer, 0, sizeof(buffer));
	printf("Before reading \n");
	nbytes = read(sock, buffer, 200);
	printf("Read count: %d\n", nbytes);

	printf("Message Received: %s\n", buffer);	


	return 0;
}
