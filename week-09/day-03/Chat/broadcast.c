#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <process.h>
#include <conio.h>
#include "broadcast.h"

void broadcast_server()
{
    struct sockaddr_in addr;
    int socketfd;
    char t = 1;

    socketfd = socket(PF_INET,SOCK_DGRAM,0);
    memset(&addr, 0, sizeof(struct sockaddr_in));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = INADDR_BROADCAST;

    if (setsockopt(socketfd, SOL_SOCKET, SO_BROADCAST , &t, sizeof(t)))
         printf("setsockopt");
    if(bind(socketfd,(struct sockaddr*) &addr,sizeof(addr)) < 0)
         printf("bind");
}

void broadcast_client()
{
    struct sockaddr_in addr;
    int socketfd;
    char t = 1;

    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&addr, 0, sizeof(struct sockaddr_in));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = INADDR_BROADCAST;

    if (setsockopt(socketfd, SOL_SOCKET, SO_BROADCAST , &t, sizeof(t)) == -1)
         printf("setsockopt");

    char data[] = "TOTORO 54445";
    struct sockaddr_in serv_addr;
    socklen_t size = sizeof(serv_addr);

    if (sendto(socketfd, data, strlen(data), 0, (struct sockaddr*)&addr, sizeof(addr)) == -1)
        printf("sendto");

    closesocket(socketfd);
}
