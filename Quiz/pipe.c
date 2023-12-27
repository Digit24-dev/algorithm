#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int fd[2];
    int input, output;
    int n; char buf[10];

    pipe(fd); // pipe CMD?! FN!?
    if (fork() == 0) {
        input = open("input", 0);
        close(fd[0]);
        while((n = read(input, buf, 10)) != 0)
            write(fd[1], buf, n);
        close(input);
        close(fd[1]);
        exit(0);
    } else {
        close(fd[1]);
        output = creat("output", 0666);
        while((n = read(fd[0], buf, 10)) != 0)
            write(output, buf, n);
        close(output); close(fd[0]);
        wait(NULL) // 왜 NULL?!
    }

}