#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    // 윗면
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 5; j++)
        {
            printf("@");
        }
        printf("\n");
    }

    // 중간
    for (int i = 0; i < 3 * n; i++)
    {
        // 좌측 골뱅이
        for (int j = 0; j < n; j++)
        {
            printf("@");
        }
        // 중앙 공백백
        for (int j = 0; j < 3 * n; j++)
        {
            printf(" ");
        }
        // 우측 골뱅이
        for (int j = 0; j < n; j++)
        {
            printf("@");
        }
        printf("\n");
    }
    // 아랫면
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 5; j++)
        {
            printf("@");
        }
        printf("\n");
    }
}