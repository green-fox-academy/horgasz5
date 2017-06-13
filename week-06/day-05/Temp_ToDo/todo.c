#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "todo.h"
#include "rs232.h"

void startup()
{
    printf("Todo application\n");
    printf("====================\n");
    printf("Commands:\n");
    printf("h    Show the command list\n");
    printf("e    Exit from the program\n");
    printf("l    List available ports\n");
    printf("p    Set port name\n");
    printf("w    Set write filename\n");
    printf("o    Open port\n");
    printf("s    Start logging / Stop logging\n");
    printf("c    Close port\n");
    printf("r    Set read filename\n");
    printf("a    Calculate average in given period\n");
    printf("====================\n");
    printf("Your command: \n");
}

void lista_init(lista *storage)
{
    storage->arr = NULL;
    storage->length = 0;
}

void lista_deinit(lista *storage)
{
    free(storage->arr);
    storage->arr = NULL;
    storage->length = 0;
}

void clrscr()
{
    system("@cls||clear");
}

 void show_comm()
{
    clrscr();
    startup();
}

int listing(lista *storage)
{
    if (storage == NULL)
        return -1;
    clrscr();
    printf("List by number\n");
    printf("====================\n");
    printf("Num | Tasks\n");
    for (int i = 0; i < storage->length; i++) {
        printf("%d  ", i + 1);
        printf(" - %s", storage->arr[i].todo);
        printf("\n");
    }
    return 0;
}

int write(lista *storage, char *path)
{
    if (storage == NULL || path == NULL)
        return -1;

    FILE *file = fopen(path, "w");
    if (file == NULL)
        return -1;

    for (int i = 0; i < storage->length; i++) {
        fprintf(file, "%s\n", storage->arr[i].todo);
    }

    fclose(file);
    return 0;
}

int read(lista *storage, char *path)
{
    if (storage == NULL || path == NULL)
        return -1;

    FILE *file = fopen(path, "r");
    if (file == NULL)
        return -1;

    char todo[MAX_LEN];

    while(fscanf(file, "%s\n", todo) == 1) {
        //add_task(storage, todo);
    }

    fclose(file);
    return 0;
}

int empt(lista *storage)
{
    if (storage == NULL)
        return -1;
    lista_deinit(storage);
    printf("No todos for today! :)\n");
    return 0;
}
