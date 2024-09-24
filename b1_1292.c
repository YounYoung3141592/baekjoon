#include <stdio.h>

int sum(int);
int getk(int);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", sum(b) - sum(a - 1));
}

int sum(int n)
{
    int k = getk(n);
    return (n - (k * (k + 1) / 2)) * (k + 1) + k * (k + 1) * (2 * k + 1) / 6;
}

// int main()
// {
//     int n = 15;
//     printf("n : %d k : %d\n", n, getk(n));
//     return 0;
// }

int getk(int n)
{
    int sum = 0, k = 1;
    while (n >= sum)
    {

        sum += k++;
        // printf("n : %d, sum : %d\n", n, sum);
    }
    return k - 2;
}