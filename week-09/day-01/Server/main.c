#define _WIN32_WINNT    0x0501
#define NI_MAXHOST      1025
#define NI_MAXSERV      32

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <arpa/inet.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int main()
{
    //Initialize WinSock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOK = WSAStartup(ver, &wsData);
    if (wsOK != 0)
    {
        printf("Can't initialize Winsock! Quitting\n");
        return -1;
    }

    //Create socket
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET)
    {
        printf("Can't create a socket! Quitting\n");
        return -1;
    }

    printf("Startup...\n");

    //Bind the ip address and port to a socket
    struct sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.s_addr = INADDR_ANY;
    memset(hint.sin_zero, '\0', sizeof(hint.sin_zero));

    bind(listening, (struct sockaddr*)&hint, sizeof(hint));

    //Tell WinSock the socket is for listening
    listen(listening, SOMAXCONN);

    //Wait for a connection
    struct sockaddr_in client;
    int clientSize = sizeof(client);

    SOCKET clientSocket = accept(listening, (struct sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];              //Client's remote name
    char service[NI_MAXSERV];           //Service (i.e. port) the client is connect on

    ZeroMemory(host, NI_MAXHOST);       //same as: memset(host, 0, NI_MAXHOST);
    ZeroMemory(service, NI_MAXSERV);

    if (getnameinfo((struct sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        printf("%s connected on port: %d\n", host, service);
    }
    else
    {
        //inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        inet_ntoa(client.sin_addr);
        printf("%s connected on port: %d\n", host, ntohs(client.sin_port));
    }

    //Close listening socket
    closesocket(listening);

    //While loop: accept and echo message back to client
    char buf[4096];

    while (1)
    {
        ZeroMemory(buf, 4096);

        //Wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == SOCKET_ERROR)
        {
            printf("Error in recv(). Quitting\n");
            break;
        }
        if (bytesReceived == 0)
        {
            printf("Client disconnected.\n");
            break;
        }

        printf(">%s\n", buf);

        //Echo message back to client
        send(clientSocket, buf, bytesReceived + 1, 0);
    }

    //Close the socket
    closesocket(clientSocket);

    //Cleanup WinSock
    WSACleanup();

    return 0;
}
