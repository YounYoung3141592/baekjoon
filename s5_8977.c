#include <stdio.h>
#include <stdlib.h>

/*
화면에 정수 하나가 나오고 매 분마다 바뀜
참여자는 b번째부터 k개의 수의 합을 맞춰야함 : a(b)~a(b+k-1)
정수는 사실 한 패턴이 반복된다.
합을 맞춰보자.
*/
long long sumAll(int *, int);
long long sumSome(int *, int, int, int);
int main()
{
    int n, k, b;
    long long sum = 0;
    scanf("%d %d %d", &n, &k, &b);
    int *pattern = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", pattern + i);
    }

    // test input
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", pattern[i]);
    // }

    sum = (long long)(k / n) * sumAll(pattern, n);
    // printf("%lld\n", sum);
    for (int i = b % n - 1; i < b % n - 1 + k % n; i++)
    {
        sum += (long long)pattern[i % n];
    }
    // sum -= sumSome(pattern, n, b, k % n);
    printf("%lld\n", sum);
    return 0;
}

long long sumAll(int *aray, int n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += aray[i];
    }
    return sum;
}

// long long sumSome(int* aray,int n,int b,int g){
// // b번째부터 g개의 합을 더한다.
//     long long sum = 0;
//     int index=b-1, count=0;
//     while(count<g){
//         if()
//     }
// }