/*
https://www.youtube.com/watch?v=KdwiF_6ZvNw&t=1186s
Лекция Хирьянова
Сортировка подсчетом
*/

#include <stdio.h>
#include <stdbool.h>
#include "iso646.h"

// #include "ctype.h" // пытался обработать нецифры с помощью isdigit
//https://ru.wikipedia.org/wiki/Ctype.h

void print_array( int array[], int N)
{
    
    for( int i = 0; i < N; i++)
        printf("%d", array[i]);
    printf("\n");   
}
 
int main()
{
   
    int counters[10] = {0};//массив счетчиков который можно иниц нулями


/*первая часть сортировки подсчетом - частотный анализ*/
    int x;
    while(true)// запуск бесконечного цикла
    {
        scanf("%3d", &x); // считывание значений (ввод пользователем) ширина3
        if (x == 10) // при вводе числа 10 закрываем ввод пользователем (терминатор. точка) 
            break;
        if(x < 0 or x > 9) // если будет что-то другое кроме цифр 0-9
            continue; // просто скипаем (но можно тут и обработать ошибку)

        counters[x] += 1; //подсчет следующего такого же числа
    }
    // print_array(counters, 10); //вывод индексов-счетчиков массива
    for (x = 0; x < 10; x++) // переход по индексам массива
        for(int i = 0; i < counters[x]; i++)  // проход от 0 нулевого индекса и далее
            printf("%3d", x);
    return(0);
}

/*
*/