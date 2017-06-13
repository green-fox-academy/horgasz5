#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED

#define MAX_LEN 255

typedef struct {
    char todo[255];
}doing;

typedef struct {
    doing *arr;
    unsigned int length;
}lista;

void startup();
void clrscr();
void lista_init(lista *storage);
void lista_deinit(lista *storage);
void show_comm();
int listing(lista *storage);
int write(lista *storage, char *path);
int read(lista *storage, char *path);
int empt(lista *storage);

#endif // TODO_H_INCLUDED
