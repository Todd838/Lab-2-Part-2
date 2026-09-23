#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int fired = 0;
int alarm_count = 0;
time_t start_time;

void alarm_handler(int signum) {
    printf("Hello World!\n");
    fflush(stdout);
    alarm_count++;
    fired = 1;
    alarm(5);
}

void sigint_handler(int signum) {
    time_t end_time = time(NULL);
    printf("\nTotal execution time: %ld seconds\n", (long)(end_time - start_time));
    printf("Number of alarms: %d\n", alarm_count);
    exit(0);
}

int main() {
    start_time = time(NULL);
    signal(SIGALRM, alarm_handler);
    signal(SIGINT, sigint_handler);
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
