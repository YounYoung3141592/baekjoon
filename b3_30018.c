#include <stdio.h>
#include <stdlib.h>

/*
input
대여소 n개, 대여소마다 자전거 a1~an개, 서비스 후 대여소마다 자전거 b1~bn개

output
b1~bn -> a1~an 을 진행할 때, 옮겨야하는 자전거의 최소 횟수


output을 만족하는 횟수는, 각 대여소마다 a-b의 절대값을 다 더해서 2로 나눈 것과 같다.
*/
int main()
{
    int n;
    scanf("%d", &n);
    int *beforeService = (int *)malloc(n * sizeof(int));
    int *afterService = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &beforeService[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &afterService[i]);
    }

    // 입력 확인
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", beforeService[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", afterService[i]);
    // }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (beforeService[i] - afterService[i] > 0) ? beforeService[i] - afterService[i] : afterService[i] - beforeService[i];
    }
    printf("%d", sum / 2);
    return 0;
}