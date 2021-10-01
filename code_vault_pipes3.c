/* 
Working with multiple pipes
source: https://code-vault.net/course/46qpfr4tkz:1603732431896/lesson/mrvonl5pmz:1603732432986

создание двух дочерних и прибавление в каждом по 5 
Игра с FD (3 функции pipe, по 2 fd на каждую функцию) Итого 6 фд на 3 процесса = 18 фд
Нужно внимательно смотреть в каком процессе какие фд закрывать Я чуть не уснул
Есть решение через цикл
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int fd[3][2];
    int i;
    for (i = 0; i < 3; i++) {
        if (pipe(fd[i]) < 0) {
            return 1;
        }
    }
    
    int pid1 = fork();
    if (pid1 < 0) {
        return 2;
    }
    
    if (pid1 == 0) {
        // Child process 1
        close(fd[0][1]);
        close(fd[1][0]);
        close(fd[2][0]);
        close(fd[2][1]);
        int x = 0;
        if (read(fd[0][0], &x, sizeof(int)) < 0) {
            return 3;
        }
        x += 5;
        if (write(fd[1][1], &x, sizeof(int)) < 0) {
            return 4;
        }
        close(fd[0][0]);
        close(fd[1][1]);
        return;
    }
    
    int pid2 = fork();
    if (pid2 < 0) {
        return 5;
    }
    
    if (pid2 == 0) {
        // Child process 2
        close(fd[0][0]);
        close(fd[0][1]);
        close(fd[1][1]);
        close(fd[2][0]);
        int x = 0;
        if (read(fd[1][0], &x, sizeof(int)) < 0) {
            return 6;
        }
        x += 5;
        if (write(fd[2][1], &x, sizeof(int)) < 0) {
            return 7;
        }
        close(fd[1][0]);
        close(fd[2][1]);
        return;
    }
    
    // Parent process
    close(fd[0][0]);
    close(fd[1][0]);
    close(fd[1][1]);
    close(fd[2][1]);
    int x = 0;
    if (write(fd[0][1], &x, sizeof(int)) < 0) {
        return 8;
    }
    if (read(fd[2][0], &x, sizeof(int)) < 0) {
        return 9;
    }
    printf("Result is %d\n", x);
    close(fd[0][1]);
    close(fd[2][0]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}