#include <stdio.h>

int main()
{
    // 찰리야 한국말로 해라
    int hour, minute;
    scanf("%d %d", &hour, &minute);
    printf("%d", (hour - 9) * 60 + minute);
    return 0;
}