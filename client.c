#include <netdb.h> 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>
#include <sys/socket.h>  
#define PORT 8080 
#define SA struct sockaddr


void temp_CS(int sockfd) 
{ 
    int a,i; 
    int uid=100;
    int n; 
    for (;;) { 
        bzero(a, sizeof(a)); 
        srand(time(0));
	a=rand()%30+300;
        write(sockfd, a, sizeof(a)); 
        bzero(a, sizeof(a)); 
        read(sockfd, a, sizeof(a));
    } 
} 

void accl_rocket(int sockfd)
{
    int a,i;  
    int uid=200;
    int n;
    for (;;) {
        bzero(a, sizeof(a));      
        srand(time(0));
        a=rand()%2+20;
        write(sockfd, a, sizeof(a));                  
        bzero(a, sizeof(a));       
        read(sockfd, a, sizeof(a));
    } 
} 
  
void temp_thrust(int sockfd)
{
    int a,i;  
    int uid=300;
    int n;
    for (;;) {
        bzero(a, sizeof(a));      
        srand(time(0));
        a=rand()%-100+100;
        write(sockfd, a, sizeof(a));                  
        bzero(a, sizeof(a));       
        read(sockfd, a, sizeof(a));
    } 
}

void gyro_rocket(int sockfd)
{
    int a,i;  
    int uid=400;
    int n;
    for (;;) {
        bzero(a, sizeof(a));      
        srand(time(0));
        a=rand()%360;
        write(sockfd, a, sizeof(a));                  
        bzero(a, sizeof(a));       
        read(sockfd, a, sizeof(a));
    } 
}


int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT);  
   // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
    // function for chat 
    func(sockfd); 
  
    // close the socket 
    close(sockfd); 
} 
