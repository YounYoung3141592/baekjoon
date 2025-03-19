#include <stdio.h>
#include <stdlib.h>
/*
1<=n<=50인 수 n
칠판에 적힌 수 n개
칠판에 적힌수 k가 k개 있으면 참이다.
*/
int main()
{
    // 초기 입력 처리
    int n;
    scanf("%d", &n);
    int *chalkboard = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &chalkboard[i]);
    }

    // 기록할 배열 생성 및 초기화
    int result[51];
    for (int i = 0; i < 51; i++)
    {
        result[i] = 0;
    }

    // 기록
    for (int i = 0; i < n; i++)
    {
        result[chalkboard[i]]++;
    }

    // // test
    // for (int i = 0; i < 50; i++)
    // {
    //     printf("result %2d : %d\n", i, result[i]);
    // }

    // 가능한 답중 가장 큰 답 출력
    for (int i = 50; i >= 0; i--) // 참인 문장이 1개 이상 존재하는 경우우
    {
        if (result[i] == i)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");

    return 0;
}