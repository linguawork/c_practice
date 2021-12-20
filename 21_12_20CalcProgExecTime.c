/*
https://stackoverflow.com/questions/5248915/execution-time-of-c-program

Как посчитать время исполнения программы

Один способ: $ time ./a.out

второй способ ниже

*/
// #include <time.h>
// #include <stdio.h>

// clock_t begin = clock();

// /* here, do your time-consuming job */

// clock_t end = clock();
// double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


#include<time.h>
#include<stdio.h>

int main()
{
    clock_t begin=clock();

    int i;
    for(i=0;i<100000;i++)
    {
        printf("%d\n",i);
        if (i == 1 || i == 99999)
            printf("%d\n",i);
    }
    
    clock_t end=clock();
    printf("Time taken:%lf",(double)(end-begin)/CLOCKS_PER_SEC);
    printf("\n");
}



