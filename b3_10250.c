#include <stdio.h>

void print(int, int, int);

int main()
{
    int h, w, t, guest;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &h, &w, &guest);
        print(h, w, guest);
    }
    return 0;
}

void print(int h, int w, int n)
{
    int floor = (n % h == 0) ? h : n % h;
    int room = (n % h == 0) ? n / h : (n / h) + 1;
    if (room < 10)
    {
        printf("%d0%d\n", floor, room);
    }
    else
    {
        printf("%d%d\n", floor, room);
    }
    return;
}