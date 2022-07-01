// стр 406 Столярова пример ls -lR | grep '^d'

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int fd[2]; // массив файлов (0 и 1) 0 на чтение (ввод), а 1 на запись (вывод)
	pipe(fd);
	if (fork() == 0)
	{
		close(fd[0]); // в этом процессе закрываем трубу на ввод (0 чтение)
		dup2(fd[1], 1);// стандартный выход в канал (делаем запись в первый файл, и выводим в терминал) по сути копируем 
		close(fd[1]); // закрываем выход (1 письмо)
		execlp("ls", "ls", "-lR", NULL); // запуск
		perror("ls"); // вывод ошибки
		exit(1);
	}
	if (fork() == 0)
	{
		close(fd[1]);// закрытие выхода из процесса
		dup2(fd[0], 0); // копирование входа в stdin те в программу
		close(fd[0]);// закрываем вход на чтение в программу те stdin
		execlp("grep", "grep", "^d", NULL);
		perror("grep");
		exit(1);
	}
		close(fd[0]); // закр вход
		close(fd[1]); // закр выход
		wait (NULL);
		wait (NULL);
		return(0);

}