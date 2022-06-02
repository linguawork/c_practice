#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int i;
	int j;
    char *v[4]={"akjhg","bhgf","cjhgf","dutyf"};
    char **answers[4]; // нужно маллочить под число команд // команды надо посчитать
    
	i = 0;
	while (i < 4) 
	{
   		// strcpy(answers[i], v[i]);
		   answers[i] = &v[i];
		   i++;
	}

    for(i=0;i<4;i++)
	{
        printf("%s\n",*answers[i]);
    }
	// sleep(100);
}