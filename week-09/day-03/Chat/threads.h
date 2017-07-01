#ifndef THREADS_H_INCLUDED
#define THREADS_H_INCLUDED

char host_name[255];

struct online_users {
    uint32_t ipaddr;
    int port;
    char user_name[255];
};

void clrscr();
void startup();
void set_host_name();

#endif // THREADS_H_INCLUDED
