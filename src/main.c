#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    for (int i = 0; i < 10; i++) {
        if (pid > 0)
        pid = fork();
    }

    if (pid > 0) {
        
    } else if (pid == 0) {

    } else 
        printf ("error happened\n");
}