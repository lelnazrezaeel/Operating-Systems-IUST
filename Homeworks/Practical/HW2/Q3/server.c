#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>



// in your browser type: http://localhost:8090
// IF error: address in use then change the PORT number
#define PORT 8090

int *clone(int *socket)
{
    int *socket_clone = malloc(sizeof(int));
    *socket_clone = *socket;
    return socket_clone;
}

void *acceptRequest(void *argSocket)
{
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
    int *new_socket = (int *) argSocket;
    
    char buffer[30000] = {0};
    long valread = read(*new_socket , buffer, 30000);

    printf("%s\n",buffer );
    write(*new_socket, hello, strlen(hello));
    printf("-------------Hello message sent---------------\n");

    close(*new_socket);
    pthread_exit(EXIT_SUCCESS);
}


int main(int argc, char const *argv[])
{
    int server_fd, new_socket; long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
        
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }
    

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 10) < 0)
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        //Create a new thread
        pthread_t pthread;

        pthread_create(&pthread, NULL, acceptRequest, clone(&new_socket));
        
    }
    return 0;
}

