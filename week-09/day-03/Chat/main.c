#define _WIN32_WINNT    0x0501
#define NI_MAXHOST      1025
#define NI_MAXSERV      32

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <process.h>
#include <conio.h>
#include "threads.h"
#include "server.h"
#include "client.h"
#include "broadcast.h"

#define MAX_LEN 255

#define COM_HELP    'h'
#define COM_EXIT    'e'
#define COM_NAME    'n'
#define COM_LIST    'l'
#define COM_DISCO   'd'
#define COM_MSG     'm'

char host_name[255];

int main()
{
    //Initialize WinSock
    WSADATA data;
    WORD ver = MAKEWORD(2, 2);
    int wsResult = WSAStartup(ver, &data);
    if (wsResult != 0)
    {
        printf("Can't start Winsock: %d\n", wsResult);
        return -1;
    }

    char command;

    _beginthread(server, 0, NULL);

    printf("Press \"h\" to menu\n");
    while (1) {
        if (kbhit()) {
            command = getch();
            switch (command)
            {
                case COM_HELP:
                    startup();
                    break;
                case COM_EXIT:
                    clrscr();
                    printf("EXIT\n");
                    return 0;
                    break;
                case COM_NAME:
                    set_host_name();
                    break;
                case COM_LIST:
                    //lista();
                    break;
                case COM_DISCO:
                    broadcast_client();
                    break;
                case COM_MSG:
                    _beginthread(client, 0, NULL);
                    break;
            }
        }
    }

    //Cleanup WinSock
    WSACleanup();
    return 0;
}
