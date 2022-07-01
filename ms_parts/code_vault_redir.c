/* создание файла. замена stdout файлом и печать в файл
источникЖ https://code-vault.net/course/46qpfr4tkz:1603732431896/lesson/43zvcsz6o1:1603732432539

Redirecting standard output in C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }
    
    if (pid == 0) {
        int file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
        if (file == -1) {
            return 2;
        }
        printf("The fd to pingResults: %d\n", file);
        dup2(file, STDOUT_FILENO);
        close(file);
        
        int err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
        if (err == -1) {
            printf("Could not find program to execute or other error ocurred\n");
            return 2;
        }
    } else {
        int wstatus;
        wait(&wstatus);
        
        if (WIFEXITED(wstatus)) {
            int statusCode = WEXITSTATUS(wstatus);
            if (statusCode == 0) {
                printf("Success\n");
            } else {
                printf("Failure with status code %d\n", statusCode);
            }
        }
    }

    return 0;
}