#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main ()
{
	int file;

	if (fork() == 0)
	{
		file = open("Results1.dat", O_WRONLY | O_CREAT, 0777); // создается файл с номером 3
		if (file == -1)
			return(1); 
		printf("The fd to Results1: %d\n", file); // печать номера 3
		dup2(file, STDOUT_FILENO); // файл дескр 3 забирает номер у stdout, 1)
		close(file);// закрытие фд3 так как он сдублировался в фд1
	}

		return(0);

}