#include <stdio.h>

int main()
{
     int num=123;

     //A normal pointer singlePointer
     int *singlePointer = NULL;

     //This pointer doublePointer is a double pointer
     int **doublePointer = NULL;

     //Assigning the address of variable num to the single pointer
     singlePointer = &num;

     //Assigning the address of pointer singlePointer to the doublePointer
     doublePointer = &singlePointer;


/* Possible ways to find value of variable num*/
     printf("\n Value of num is: %d", num);
     printf("\n Value of num using singlePointer is: %d", *singlePointer); //разыменование = получаем то что лежит в ячейке
     printf("\n Value of num using doublePointer is: %d", **doublePointer);//двойное разыменование = получаем то что лежит в ячейке

     /*Possible ways to find address of num, Печатаем через P*/
     printf("\n Address of num is: %p", &num); // печать адреса (через &) ячейки, в которой переменная NUM
     printf("\n Address of num using singlePointer is: %p", singlePointer);// тоже печать адреса переменной NUM
     printf("\n Address of num using doublePointer is: %p", *doublePointer); //тоже печать адреса переменной NUM

     /*Find value of pointer*/
     printf("\n Value of Pointer singlePointer is: %p", singlePointer);// печать значения указателя те адрес ячейки на которую указывает указатель (как и выше)
     printf("\n Value of Pointer singlePointer using doublePointer is: %p", *doublePointer); // печать значения указателя те адрес ячейки на которую указывает указатель (как и выше)

     /*Ways to find address of pointer*/
     printf("\n Address of Pointer singlePointer is:%p",&singlePointer); // печать адреса самого указателя через &
     printf("\n Address of Pointer singlePointer using doublePointer is:%p",doublePointer);// печать адреса самого указателя doublePointer = &singlePointer;

     /*Double pointer value and address*/
     printf("\n Value of Pointer doublePointer is:%p",doublePointer); //адрес ячейки на которую указывает двойной указатель
     printf("\n Address of Pointer doublePointer is:%p",&doublePointer); // адрес самого двойного указателя

     return 0;
}
