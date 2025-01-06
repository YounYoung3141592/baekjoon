#include <stdio.h>

/*
50개의 봉투중 하나에 토끼(토끼 카드)가 숨겨져있음
숫자 하나를 고르면 높낮 말해줌
binary search를 통해 고른 봉투를 계속 나열함.
*/

void binarySearchRabbit(int, int, int);
int main()
{
    int rabbit;
    scanf("%d", &rabbit);
    while (rabbit != 0)
    {
        binarySearchRabbit(rabbit, 1, 50);
        scanf("%d", &rabbit);
    }
    return 0;
}

void binarySearchRabbit(int rabbit, int start, int end)
{
    int middle = (end + start) / 2;
    printf("%d ", middle);
    if (rabbit == middle)
    {
        printf("\n");
        return;
    }
    else if (rabbit > middle)
    {
        binarySearchRabbit(rabbit, middle + 1, end);
    }
    else
    {
        binarySearchRabbit(rabbit, start, middle - 1);
    }
}