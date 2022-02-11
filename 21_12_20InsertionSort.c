#include <stdio.h>
/*
https://www.youtube.com/watch?v=ZxpcEQcqHWU&list=PLYlfM6qKBI5iAVpjYmLnM36VOBgny7eqN&index=1
Лекция Хирьянова
Сортировка вставкой

Эта версия без сортировки Просто ввод и вывод массива
*/

#include <stdio.h>
#include <stdbool.h>
#include "iso646.h"
 
#define ALLOCATESIZE 1000 //ввели константу для глобального определения размера буфера

void print_array( int array[], int N)
{
    
    for( int i = 0; i < N; i++)
        printf("%d", array[i]);
    printf("\n");   
}

int  input_array(int arr[], int max_size)
{
    int array_index;
    int user_input;

    array_index = 0;

    while(1)//true
    {
        scanf("%d", &user_input);
        if(user_input == 0 or user_input == max_size)
            break;
        arr[array_index] = user_input;
        array_index++;
    }
    return array_index;//cуммарное значение индексов

}
 
int main( int argc, char *argv[]) // or char **argv
{
    printf("Enter numbers:\n");
    int Array[ALLOCATESIZE];
    int Index;

    Index = input_array(Array, ALLOCATESIZE);//ввод юзером чисел в массив
    print_array(Array, Index); //распечатка массива


    return(0);
}