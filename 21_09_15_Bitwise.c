/*
https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
Источник
*/


// C Program to demonstrate use of bitwise operators
#include <stdio.h>
int main()
{
    // a = 5(00000101), b = 9(00001001)
    unsigned char a = 5, b = 9;
 
    // The result is 00000001
    printf("a = %d, b = %d\n", a, b);
    printf("a&b = %d\n", a & b);
 
    // The result is 00001101
    printf("a|b = %d\n", a | b);
 
    // The result is 00001100
    printf("a^b = %d\n", a ^ b);
 
    // The result is 11111010
    printf("~a = %d\n", a = ~a);
 
	//b = 9(00001001)
    // The result is 00010010
    printf("b<<1 = %d\n", b << 1); // при смещении влево на один бит получается число в 2 раза больше = 18
 
	//b = 9(00001001)
    // The result is 00000100
    printf("b>>1 = %d\n", b >> 1); // при смещении вправо на один бит получается число в 2 раза меньше = 4 (%2)
	// не 4,5 получится 4
 
    return 0;
}