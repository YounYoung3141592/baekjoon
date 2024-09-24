#include <stdio.h>

int main()
{
    int hour, minute, second;
    scanf("%d %d %d", &hour, &minute, &second);
    int cooking;
    scanf("%d", &cooking);
    second += cooking;
    while (second >= 60)
    {
        second -= 60;
        minute++;
    }
    while (minute >= 60)
    {
        minute -= 60;
        hour++;
    }
    while (hour >= 24)
    {
        hour -= 24;
    }
    printf("%d %d %d", hour, minute, second);
    return 0;
}