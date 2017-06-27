#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>

// Create Server and Client Applications that send and receive messages.

int main()
{
    char ipaddress[] = "127.0.0.1";       //IP Address of the server
    int port = 54000;                   //port on server

    //Initialize WinSock
    WSADATA data;
    WORD ver = MAKEWORD(2, 2);
    int wsResult = WSAStartup(ver, &data);
    if (wsResult != 0)
    {
        printf("Can't start Winsock: %d\n", wsResult);
        return -1;
    }

    //Create socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
    {
        printf("Can't create socket: %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
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
    do
    {
        //Prompt the user for some text
        printf(">");
        gets(userInput);
        if (strlen(userInput) > 0)      //Make sure the user has typed in something
        {
            //Send the text
            int sendResult = send(sock, userInput, strlen(userInput), 0);
            if (sendResult != SOCKET_ERROR)
            {
                //Wait for response
                ZeroMemory(buf, 4096);
                int bytesReceived = recv(sock, buf, 4096, 0);
                if (bytesReceived > 0)
                {
                    //Echo response to console
                    printf("SERVER> %s, 0, %d\n", buf, bytesReceived);
                }
            }
        }

    } while (sizeof(userInput) > 0);

    //Gracefully close down everything
    closesocket(sock);
    WSACleanup();

    return 0;
}
