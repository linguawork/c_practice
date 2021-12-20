/*
https://www.geeksforgeeks.org/difftime-c-library-function/

Как посчитать время исполнения программы

Один способ: $ time ./a.out

третий способ ниже

*/



#include<time.h>
#include<stdio.h>

int main()
{
    time_t time0;
    time_t time1;

    time (&time0);
    int i;
    for(i=0;i<100000;i++)
    {
        printf("%d\n",i);
    }
    
    time (&time1);
    
    printf("Time taken:%lf", difftime(time1, time0));// округление до секунд
}