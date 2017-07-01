#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <conio.h>

void client()
{
    char ipaddress[] = "127.0.0.1";       //IP Address of the server
    int port = 54000;                   //port on server

    //Create socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
    {
        printf("Can't create socket: %d\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    //Fill in a hint structure
    struct sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    hint.sin_addr.s_addr = inet_addr(ipaddress);
    memset(hint.sin_zero, '\0', sizeof(hint.sin_zero));

    //Connect to server
    int connResult = connect(sock, (struct sockaddr*)&hint, sizeof(hint));
    if (connResult == SOCKET_ERROR)
    {
        printf("Can't connect to server: %d\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
        return;
    }

    //Do-While loop to send and receive data
    char buf[4096];
    char userInput[4096];

    //Prompt the user for some text
    printf(">");
    gets(userInput);
    if (strlen(userInput) > 0)      //Make sure the user has typed in something
    {
        //Send the text
        int sendResult = send(sock, userInput, strlen(userInput), 0);
    }

    //Gracefully close down everything
    closesocket(sock);

    return;
}
