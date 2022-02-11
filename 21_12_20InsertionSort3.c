#include <stdio.h>
/*
https://www.youtube.com/watch?v=ZxpcEQcqHWU&list=PLYlfM6qKBI5iAVpjYmLnM36VOBgny7eqN&index=1
Лекция Хирьянова
Сортировка вставкой

Эта версия с сортировкой


Для замера времени исполнения программы перед выводом бинарного
файла писать time
например:
time ./a.out



*/

#include <stdio.h>
#include <stdbool.h>
#include "iso646.h"
#include <time.h>
 
#define ALLOCATESIZE 1000 //ввели константу для глобального определения размера буфера

void print_array( int array[], int N)
{
    
    for( int i = 0; i < N; i++)
        printf("%d", array[i]);
    printf("\n");   
}

void insertion_sort (int Arr[], int N)
{
    for(int i = 1; i < N; i++) // нолевой уже находится на месте
    {
        int k = i; // копирование ячейки с которой стартуем
        while (k > 0 && Arr[k-1] < Arr[k])// for descending order we change sign <, the rest is the same
        {
            //swap - меняем местами - меньшее двигаем вправо
            //https://www.includehelp.com/c-programs/insertion-sort-example-in-data-structure.aspx
            int tmp = Arr[k-1];// сохраняем значение левого (он меньше)
            Arr[k-1] = Arr[k]; // значение левого перезаписываем правым (вместо меньшего ставим бОльшим)
            Arr[k] = tmp;// значение правого перезаписываем сохраненным значением левого (большее заменяем меньшим)
            //при этом сами названия переменных не меняем
            k -= 1; //переходим на след элемент левее
            //https://www.youtube.com/watch?v=ROalU379l3U
            //сортировка в танце
        } 
    }
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
     clock_t begin;
     begin = clock();

    printf("Enter numbers:\n");
    int Array[ALLOCATESIZE];
    int Index;

    Index = input_array(Array, ALLOCATESIZE);//ввод юзером чисел в массив
    insertion_sort (Array, Index);
    print_array(Array, Index); //распечатка массива

    clock_t end;
    end = clock();

    printf("Time taken:%lf",(double)(end-begin)/CLOCKS_PER_SEC);
    printf("\n");

    return(0);
}