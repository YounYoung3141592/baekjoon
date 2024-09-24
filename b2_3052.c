#include <stdio.h>

int check(int, int aray[10], int);
int main()
{
    int dividedBy42[10], soleValue[10] = {
                             -1,
                         },
                         svIndex = 0, count = 0;
    for (int i = 0; i < 10; i++)
    {
        int temp;
        scanf_s("%d", &temp, sizeof(temp));
        dividedBy42[i] = temp % 42;
    }
    for (int i = 0; i < 10; i++)
    {
        // sv에 해당 수가 있으면 넘어가고, 없으면 카운트++ 하고 sv에 추가하기
        count += check(dividedBy42[i], soleValue, svIndex);
    }
    printf("%d\n",count);
    return 0;
}

int check(int n, int soleValue[10], int svIndex)
{
    for (int i = 0; i < svIndex; i++)
    {
        if (n == soleValue[i])
        {
            return 0;
        }
    }
    return 1;
}