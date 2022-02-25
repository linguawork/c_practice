/*
https://code-live.ru/forum/cpp/394/
КОд на плюсах переделал в Си
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
    t_sorted arr[10]; // создаем массив структур из 100 элементов-структур
    // srand(time(NULL));
    for (int i = 0; i < 10; ++i) { // бежим по массиву
        arr[i].val = rand();// заполняем рандомными значениями
		printf("value = %d, ", arr[i].val);
        arr[i].i = i; // первоначальное значение индекса
		printf("index = %d\n", arr[i].i);

		// printf("i = %d\n", arr[i].i);

    }

		printf("__value = %d, ", arr[2].val);// распечатка значения второй структуры
		printf("__index = %d\n", arr[2].i);// распечатка индекса второй структуры

		// в структуре - элементе массива структур сохраняется и значение и индекс
    return 0;
}