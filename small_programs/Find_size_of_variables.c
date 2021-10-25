#include <stdio.h>

/* источник https://www.programiz.com/c-programming/examples/add-numbers */
/* https://www.tutorialspoint.com/what-is-the-correct-way-to-use-printf-to-print-a-size-t-in-c-cplusplus */


int main()
{
	int int_var;
	float float_var;
	double double_var;
	char char_type;

	/* sizeof() подсчитывает размер переменной */

	printf("The size of int is: %zu bytes\n", sizeof(int_var));
	// printf("The size of int is: %d bytes\n", sizeof(int_var)); // compiler asked for %lu, %d also worked
	printf("Size of float: %zu bytes\n", sizeof(float_var));
    printf("Size of double: %zu bytes\n", sizeof(double_var));
    printf("Size of char: %zu byte\n", sizeof(char_type));
	return (0);
}