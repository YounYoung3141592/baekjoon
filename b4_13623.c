#include <stdio.h>

int main()
{
    int input[3];
    scanf("%d %d %d", &input[0], &input[1], &input[2]);
    if ((input[0] == input[1]) && (input[1] == input[2]))
    {
        printf("*\n");
    }
    else if (input[0] == input[1])
    {
        printf("C\n");
    }
    else if (input[0] == input[2])
    {
        printf("B\n");
    }
    else
    {
        printf("A\n");
    }
    return 0;
}