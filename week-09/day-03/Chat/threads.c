#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <conio.h>
#include <process.h>
#include "threads.h"

void clrscr()
{
    system("@cls||clear");
}

void startup()
{
    clrscr();
    printf("====================\n");
    printf("TOTORO CHAT\n");
    printf("====================\n");
    printf("Commands:\n");
    printf(" h   Display this help info\n");
    printf(" e   Exit\n");
    printf(" n   Set user name\n");
    printf(" l   List known users\n");
    printf(" d   Send discovery request\n");
    printf(" m   Send message\n");
    printf("====================\n");
    printf("Your command: \n");
}

void set_host_name()
{
    printf("What is your host name?\n");
    scanf("%s", host_name);
    printf("Host name: %s\n", host_name);
}
