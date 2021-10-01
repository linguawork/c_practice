#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main ()
{
    int fd;
    int saved_stdout;

    char *command = "ls";
    char *output = ">";
    char *file = "f1";

    if (!command && output && file )// без команды cоздание файла > fd
    {
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644); // empty file
        if (fd == -1)
            exit(1);
    }
    if (command && output && file )// команда редирект и файл
    {
        saved_stdout = dup(1);
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
            exit(1);
//            printf("The fd to file1: %d\n", file1); // печать номера 3
        dup2(fd, STDOUT_FILENO); // файл дескр 3 забирает номер у stdout, 1)
        close(fd);// закрытие фд3 так как он сдублировался в фд1
        
        dup2(saved_stdout, 1);
        close(saved_stdout);
    }
