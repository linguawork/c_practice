/*
When working on Push_swap
met some explicit explanation of bitwise operations and printing the result

Very informative article: 
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
*/

#include"stdio.h"


int main()
{
	int num;

	num = 36;
/*
0000 ... 0010 0100 -> 36
Right shift 2 bits
0000 ... 0000 1001 -> 9

If we use the >> operator in C
*/
	printf("%d\n", num>>2); // output is 9

/**************************************************/

/*
6&5
6   : 0000 ... 0 1 1 0
5   : 0000 ... 0 1 0 1
6&5 : 0000 ... 0 1 0 0 -> 4
*/

/*
For two integers, & will perform on every bit. For example
*/
	printf("%d\n", 6&5); //output is 4

	return(0);
}