#include <stdio.h>
#include <string.h>

int main()
{
    char str[2][100];
    scanf("%[^\n]%*c", str[0]);
    int length = strlen(str[0]);
    int i, j;
    for (i = 0, j = length - 1; i < length; i++, j--)
    {
        str[1][i] = str[0][j];
    }
    printf("%s\n", str[0]);
    printf(" %s\n", str[1]);
    return 0;
}