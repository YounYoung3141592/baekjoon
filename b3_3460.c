#include <stdio.h>

void print(int);
int main()
{
    int gasu;
    scanf("%d", &gasu);
    for (int i = 0; i < gasu; i++)
    {
        int temp;
        scanf("%d", &temp);
        print(temp);
        printf("\n");
    }
    return 0;
}

void print(int n)
{
    int count = 0;
    while (n >= 2)
    {
        if (n % 2 == 1)
        {
            printf("%d ", count);
        }
        n /= 2;
        count++;
    }
    if (n == 1)
    {
        printf("%d", count);
    }
    return;
}