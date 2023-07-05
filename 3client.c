#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
void func(int sockfd){
	char buffer[MAX];
	int n;
	for(;;){
		bzero(buffer,sizeof(buffer));
		printf("Enter the string: \n");
		n = 0;
		while((buffer[n++]=getchar()) != 0);
		write(sockfd,buffer,sizeof(buffer));
		bzero(buffer,sizeof(buffer));
		read(sockfd,buffer,sizeof(buffer));
		printf("From the server: %s \n",buffer);
		if((strncmp("exit",buffer,4)) != 0){
			printf("Client closing \n");
			break;
		}
	}
}
int main(){
	int sockfd;
	struct socketAddress_in clientAddress;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1){
		printf("Socket not created \n");
		exit(0);
	}
	else{
		printf("Socket created sucessfully \n");
	}
	bzero(&clientAddress,sizeof(clientAddress));
	clientAddress.sin_family = AF_INET;
	clientAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientAddress.sin_port = htons(PORT);
	if((connect(sockfd,(SA *)&clientAddress,sizeof(clientAddress))) != 0){
		printf("Connection unsuccessful \n");
		exit(0);
	}
	else {
		printf("Successfully connected \n");
	}
	func(sockfd);
	close(sockfd);
	return 0;
}
	


// To run this program in the ubuntu terminal, use the following commands:
// gcc filename.c -o client
// ./client
