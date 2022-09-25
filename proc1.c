#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t ret;
    /* fork another process */
    ret = fork();
    if (ret < 0)
    { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        exit(-1);
    }
    else if (ret == 0)
    { /* child process */
        execlp("/bin/ls", "ls", NULL);
    }
    else
    { /* parent process */
        /* parent will wait for the child to complete */
        wait(NULL);
        printf("Child Complete\n");
        exit(0);
    }
}
