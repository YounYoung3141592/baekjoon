#include <stdio.h>
#include <stdlib.h>
/*
운동 루틴 한번에 x킬로그램씩 살이 빠짐
n일동안 수행
i번째 날에 최종 몸무게가 Ai이상이길 원함
루틴을 최대 몇번 진행할 수 있는가?
*/
int main()
{
    // 문제 입력 받기
    int n;
    long long x, routine = 0, weightNow = 0;
    scanf("%d %lld", &n, &x);
    long long *minimumWeight = (long long *)malloc(sizeof(long long) * n);
    long long *gainWeight = (long long *)malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &minimumWeight[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &gainWeight[i]);
    }

    // 입력 테스트
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", minimumWeight[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", gainWeight[i]);
    // }

    // // 예외조건 : 첫날에 최소무게>찌는무게 일때
    // if (minimumWeight[0] > gainWeight[0])
    // {
    //     printf("-1");
    //     return 0;
    // }

    // 예외조건 : 운동을 아예 하지 않아도 최소 몸무게를 넘을 수 없는 경우
    long long tempWeightSum = 0;
    for (int i = 0; i < n; i++)
    {
        tempWeightSum += gainWeight[i];
        if (tempWeightSum < minimumWeight[i])
        {
            printf("-1");
            return 0;
        }
    }

    // 시도1 : 문제의 흐름대로 따라감
    for (int i = 0; i < n; i++)
    {
        weightNow += gainWeight[i];
        if (weightNow < minimumWeight[i])
        {
            printf("-1");
            return 0;
        }
        if ((weightNow - x >= minimumWeight[i]) && (weightNow - x + gainWeight[i + 1] >= minimumWeight[i + 1]))
        {
            routine += (weightNow - minimumWeight[i]) / x;
            weightNow = (weightNow - minimumWeight[i]) % x + minimumWeight[i];
        }
        // while (weightNow - x >= minimumWeight[i])
        // {
        //     routine++;
        //     weightNow -= x;
        // }
    }
    if (routine == 0)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", routine);
    }
    return 0;

    // 시도2 : gain을 다 더하고 마지막날에 루틴 수행하는걸로 가정
    // for (int i = 0; i < n; i++)
    // {
    //     weightNow += gainWeight[i];
    //     if (weightNow < minimumWeight[i])
    //     {
    //         printf("-1");
    //         return 0;
    //     }
    // }
    // routine = (weightNow - minimumWeight[n - 1]) / x;
    // printf("%d", routine);
    // return 0;
}
