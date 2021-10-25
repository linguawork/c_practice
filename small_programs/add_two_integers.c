#include <stdio.h>

/* источник https://www.programiz.com/c-programming/examples/add-numbers */

int main()
{
	int first_number;
	int	second_number;
	int sum;

	printf("Enter two integers: ");
	scanf("%d %d", &first_number, &second_number);

	/* проведение операции */
	sum = first_number + second_number;

	printf("%d + %d = %d", first_number, second_number, sum);
	return (0);
}