#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
void func(int connectID){
	char buffer[MAX];
	int n;
	for(;;){
		bzero(buffer,MAX);
		read(connectID,buffer,sizeof(buffer));
		printf("From Client: %s \n To Client: \n",buffer);
		bzero(buffer,size);
		n = 0;
		while((buffer[n++]=getchar())!='\n');
		write(connectID,buffer,sizeof(buffer));
		if(strncmp("exit",buffer,4)==0){
			printf("Server Exit \n");
			break;
		}
	}
}
	
int main(){
	int sockfd, length, connectID;
	struct socketAddress_in serverAddress, client;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1){
		printf("Socket not created");
		exit(0);
	}
	else{
		printf("Socket successfully created \n");
	}
	bzero(&serverAddress, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(PORT);
	if(bind(sockfd,(SA *)&serverAddress,sizeof(serverAddress)) != 0){
		printf("Socket binding unsuccessful \n");
		exit(0);
	}
	else{
		printf("Socket binding successful \n");
	}
	if((listen(sockfd,5))!=0){
		printf("Server not listening \n");
		exit(0);
	}
	else{
		printf("Server listening \n");
	}
	length = sizeof(client);
	connectID = accept(sockfd, (SA*)&client, &length);
	if(connectID < 0){
		printf("Server accept failed");
	}
	else {
		printf("Server accepted the client \n");
	}
	func(connectID);
	close(sockfd);
	return 0;
}


// To run this code in terminal, give the following command:
// gcc filename.c -o server
// ./server
