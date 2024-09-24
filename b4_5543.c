#include <stdio.h>

int getMin(int a[], int);
int main()
{
    int burger[3], drink[2];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &burger[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &drink[i]);
    }
    printf("%d", getMin(burger, 3) + getMin(drink, 2) - 50);
    return 0;
}

int getMin(int a[], int length)
{
    int min = 2000;
    for (int i = 0; i < length; i++)
    {
        min = (min > a[i]) ? a[i] : min;
    }
    return min;
}