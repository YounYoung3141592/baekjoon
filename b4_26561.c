#include <stdio.h>

// emily의 나라엔 7초마다 사람이 죽고, 4초마다 새로운 사람이 태어난다.

// input : p : 현재 인구, t : 시간
long int getFuturePopulation(long int p, long int t);
int main()
{
    int lines;
    long int p, t;
    scanf("%d", &lines);
    for (int i = 0; i < lines; i++)
    {
        scanf("%d %d", &p, &t);
        printf("%ld\n", getFuturePopulation(p, t));
    }
    return 0;
}

long int getFuturePopulation(long int p, long int t)
{
    return p + (t / 4) - (t / 7);
}