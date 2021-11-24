#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int processesCount = atoi(argv[1]) - 1;
    int N = atoi(argv[2]);
    // Creating children which help in calculating
    pid_t pid = fork();
    for (int i = 0; i < processesCount; i++) {
        if (pid > 0)
        pid = fork();
    }

    // If it was the mother ...
    if (pid > 0) {
        // waits for all children to finish their work and then 
        // receives the number of secessfull dots of theirs.
        int nTotal = 0;
        for (int i = 1; i <= processesCount + 1; i++) {
            char pathname[50];
            char readyReceive[100];

            sprintf(pathname, "/tmp/process%d", getpid() + i);

            mkfifo(pathname, 0666);
            int f = open(pathname, O_RDONLY);
            read(f, readyReceive, 100);
            close(f);

            nTotal += atoi(readyReceive);
        }

        double PI = (4 * (double)nTotal / N) / (processesCount + 1);
        printf("PI is: %lf", PI);
        
    } 
    // If it was a child and here we put random dots
    else if (pid == 0) {
        srand(getpid() + time(NULL));
        int n = 0;
        for (int i = 0; i < N; i++) {
            // Generating random dot and check if that is in
            // the circle with radius of 1 or not.
            double x = (double)rand() / (double)(RAND_MAX);
            double y = (double)rand() / (double)(RAND_MAX);
            double r = sqrt(x*x + y*y);
            if (r < 1) n++;
        }
        printf("My n is:%d\n", n);
        char pathname[50];
        char readySend[100];

        sprintf(pathname, "/tmp/process%d", getpid());
        sprintf(readySend, "%d", n);

        mkfifo(pathname, 0666);
        int f = open(pathname, O_WRONLY);
        write(f, readySend, strlen(readySend) + 1);
        close(f);
        
    } else 
        printf ("error happened\n");
}