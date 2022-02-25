/*
https://code-live.ru/forum/cpp/394/
КОд на плюсах переделал в Си

второй вариант без rand
*/

#include "stdio.h"
#include <sys/time.h>
#include "stdlib.h"



typedef struct sorted {
    int val; // значение
    int i; // индекс
} t_sorted;

int main() 
{
    t_sorted arr[5]; // создаем массив структур из 100 элементов-структур
    // srand(time(NULL));
    arr[0].val = 3;// заполняем  значениями
    arr[1].val = 5;
    arr[2].val = 2;
    arr[3].val = 8;
    arr[4].val = 1;

    for (int i = 0; i < 5; ++i) { // бежим по массиву

		printf("value = %d, ", arr[i].val);
        arr[i].i = i; // первоначальное значение индекса
		printf("index = %d\n", arr[i].i);

		// printf("i = %d\n", arr[i].i);

    }

		printf("__value of the element 1 = %d, ", arr[1].val);// распечатка значения второй структуры
		printf("__index of element 1 = %d\n", arr[1].i);// распечатка индекса второй структуры

		// в структуре - элементе массива структур сохраняется и значение и индекс
    return 0;
}