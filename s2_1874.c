#include <stdio.h>
#include <stdlib.h>

// 입력 : n개의 수열이 주어진다.
// 오름차순으로 push를 진행할 때, 입력과 동일한 수열을 만들 수 있는가?

// struct stackPart{
//     int value;
//     struct stackPart *back;
//     struct stackPart *front;
// };
// void push(int **);
// void pop(int **);
int main()
{
    int n;
    scanf("%d", &n);
    // struct stackPart *door = NULL;
    int *numbers = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }
}