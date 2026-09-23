#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int fired = 0;

void handler(int signum) {
    printf("Hello World!\n");
    fflush(stdout);
    fired = 1;
    alarm(5);
}

int main() {
    signal(SIGALRM, handler);
    alarm(5);
    while (1) {
        if (fired) {
            printf("Turing was right!\n");
            fflush(stdout);
            fired = 0;
        }
    }
    return 0;
}
