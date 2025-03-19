#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findJalitsu(long long, int);
int main()
{
    long long n;
    int b;
    scanf("%lld %d", &n, &b);
    int maxJalitsu = findJalitsu(n, b); // B^k < n < B^(k-1)인 k를 구한다.
    int **result = (int **)malloc(sizeof(int *) * maxJalitsu);
    for (int i = 0; i < maxJalitsu; i++)
    {
        result[i] = (int *)malloc(sizeof(int) * 2);
        result[i][0] = i;
        result[i][1] = 0;
    }
    for (int i = maxJalitsu - 1; i >= 0; i--)
    {
        result[i][1] = n / pow(b, i);
        n = n % (long long)pow(b, i);
    }
    for (int i = maxJalitsu - 1; i >= 0; i--)
    {
        if (result[i][1] > 9)
        {
            // 알파벳으로의 변환 필요
            printf("%c", result[i][1] + 55);
        }
        else
        {
            printf("%d", result[i][1]);
        }
    }
}

int findJalitsu(long long n, int b)
{
    int k = 0;
    while (pow(b, k) <= n)
    {
        k++;
    }
    // printf("%d보다 큰 %d의 %d승은 %d이다.\n", n, b, k, (int)pow(b, k));
    return k;
}