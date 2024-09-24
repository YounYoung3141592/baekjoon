#include <stdio.h>

int getJalitsu(int);
int main()
{
    int num[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &num[i]);
    }
    printf("%d\n", num[0] + num[1] - num[2]);
    printf("%d", num[0] * getJalitsu(num[1]) + num[1] - num[2]);
    return 0;
}

int getJalitsu(int n)
{
    int result = 10;
    while (n >= result)
    {
        result *= 10;
    }
    return result;
}