#include <stdio.h>

int main()
{
    long long int n, m;

    scanf("%lld %lld", &n, &m);
    printf("%lld", n * m / 2);
    // if (n % 2 == 0)
    // {
    //     printf("%d\n", (n * m) / 2);
    // }
    // else
    // {
    //     printf("%d\n", ((n - 1) * m) / 2 + (m / 2));
    // }
    return 0;
}