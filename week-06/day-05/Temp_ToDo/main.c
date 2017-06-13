#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "todo.h"
#include "rs232.h"

#define MAX_LEN 255
#define COM_SHO "h"
#define COM_LST "e"
#define COM_WRITE "l"
#define COM_READ "p"
#define COM_EMPT "s"

int main()
{
    lista storage;
    lista_init(&storage);

    char command[MAX_LEN];
    char parse[MAX_LEN];
    startup();
    while (1) {
        gets(command);
        strcpy(parse, command);
        char *p;
        p = strtok(parse, "\"");
        if (p != NULL) {
            if (strstr(p, COM_SHO)) {
                p = strtok(NULL, "\"");
                char todo[MAX_LEN];
                strcpy(todo, p);
                show_comm();
            }else if (strstr(p, COM_LST)) {
                listing(&storage);
            } else if (strstr(p, COM_WRITE)) {
                p = strtok(NULL, "\"");
                char path[MAX_LEN];
                strcpy(path, p);
                write(&storage, path);
            } else if (strstr(p, COM_READ)) {
                p = strtok(NULL, "\"");
                char path[MAX_LEN];
                strcpy(path, p);
                read(&storage, path);
            } else if (strstr(p, COM_EMPT)) {
                empt(&storage);
            }else {
                printf("EXIT\n");
                break;
            }
        }
    }

    lista_deinit(&storage);

    return 0;
}
