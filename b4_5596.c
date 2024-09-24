#include <stdio.h>
int getSum(int a[4]);
int main()
{
    int minguk[4];
    int manse[4];
    scanf("%d %d %d %d", &minguk[0], &minguk[1], &minguk[2], &minguk[3]);
    scanf("%d %d %d %d", &manse[0], &manse[1], &manse[2], &manse[3]);
    int mingukSum = getSum(minguk), manseSum = getSum(manse), max;
    max = (mingukSum > manseSum) ? mingukSum : manseSum;
    printf("%d\n", max);
    return 0;
}

int getSum(int a[4])
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += a[i];
    }
    return sum;
}