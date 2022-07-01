
//https://code-vault.net/course/46qpfr4tkz:1603732431896/lesson/l60w4pa21h:1603732432183
// Communicating between processes (using pipes) in C

/* получение в родительском процессе числа введенного в дочернем процессе 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]) 
{
    int fd[2]; // создаем массив fd [0] и [1]
    if (pipe(fd) == -1) // cоздаем трубу (у нее есть fd[0] и fd[1])
	{
        printf("An error occurred with opening the pipe\n");
        return 1;
    }
    
    int id = fork(); // cоздаем копию род процесса в дочернем // туда же копируются фд от пайпа
    if (id == -1) 
	{
        printf("An error occurred with fork\n");
        return 2;
    }
    
    if (id == 0) 
	{
        // Child process
        close(fd[0]); // так как мы не читаем извне (не слушаем, не принимаем в дыру) то закрываем дырку (чтение в комп в STDIN: fd[0])
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1) // мы пишем в единицу
		{
            printf("An error occurred with writing to the pipe\n");
            return 3;
        }
        close(fd[1]);
    } 
	else 
	{
        // Parent process
        close(fd[1]);
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1) 
		{
            printf("An error ocurred with reading from the pipe\n");
            return 4;
        }
        printf("Got from child process %d\n", y);
        y = y * 3;
        printf("Result is %d\n", y);
        close(fd[0]);
    }
    
    return 0;
}
