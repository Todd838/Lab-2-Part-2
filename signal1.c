#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int fired = 0;

void handler(int signum) {
    printf("Hello World!\n");
    fired = 1;
}

int main() {
    signal(SIGALRM, handler);
    alarm(5);
    while (!fired);
    printf("Turing was right!\n");
    return 0;
}
