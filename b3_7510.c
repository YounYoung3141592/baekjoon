#include <stdio.h>

/*
직각삼각형
세 변의 길이 -> 직각삼각형인지 판별하기 : 피타고라스.
*/
void isitRightTriangle(int *);
void swap(int *, int *);
void findMax(int *);
int main()
{
    int n, triangle[3];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &triangle[0], &triangle[1], &triangle[2]);
        findMax(triangle); // max를 찾고, max가 0번 인덱스에 가게 해준다.
        printf("Scenario #%d:\n", i);
        isitRightTriangle(triangle);
        printf("\n\n");
    }
    return 0;
}

void findMax(int tri[3])
{
    if ((tri[1] > tri[2]) && (tri[1] > tri[0]))
    {
        // 1번이 제일 클 가능성
        swap(&tri[0], &tri[1]);
    }
    else if ((tri[2] > tri[1]) && (tri[2] > tri[0]))
    {
        // 2번이 제일 클 가능성
        swap(&tri[0], &tri[2]);
    }
    return;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void isitRightTriangle(int tri[3])
{
    if (tri[0] * tri[0] == tri[1] * tri[1] + tri[2] * tri[2])
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
}