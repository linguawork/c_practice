#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main () // function from Stolyarov book2
{
	int save1;
	int fd;

	fflush(stdout); // clean buffer
	save1 = dup(1); // saving stdout;
	int fd = open("file.dat", O_CREAT | O_WRONLY | O_TRUNC, 0666); // open file
	if (fd == -1) // if did not open
		return(1);
	dup2(fd, 1); // fd became stdout (number3 became number 1)
	close(fd); // close number 3
	// do necessary actions// execve сохраняет номера каналов файловых дескрипторов
	dup2(save1, 1); // returning the number to the duplicate of stdout: save1
	close(save1); // the copy of stdout is closed
	return(0);
}