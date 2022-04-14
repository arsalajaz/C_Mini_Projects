#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sysexits.h>

int main(void) {

/*Program 1

    pid_t pid;
    int status;

    pid = fork();

    if(pid == 0) {
        printf("Parent Process ID: %d\n", getppid());
    } else {
        wait(&status);
        printf("Child Process ID: %d\n", pid);
    }
    return 0;
*/

/*Program 2

    pid_t pid;
    int status;

    pid = fork();

    if(pid == 0) {
        execl("/bin/pwd", "pwd", (char *)NULL);
    } else {
        wait(&status);
    }
    return 0;
*/

/*Program 3

    pid_t pid;
    int status;

    pid = fork();

    if(pid == 0) {
        execl("/bin/cal", "cal", (char *)NULL);
    } else {
        wait(&status);
    }
    return 0;
*/

/*Program 4

    pid_t pid;
    int status;

    pid = fork();

    if(pid == 0) {
        exit(0);
    } else {
        wait(&status);
    }
    return 0;
*/

}