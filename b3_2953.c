#include <stdio.h>

void getWinner(int sumScore[5]);
int main()
{
    int sumScore[5] = {
        0,
    };
    for (int i = 0; i < 5; i++)
    {
        int temp[4];
        scanf("%d %d %d %d", &temp[0], &temp[1], &temp[2], &temp[3]);
        for (int j = 0; j < 4; j++)
        {
            sumScore[i] += temp[j];
        }
    }
    getWinner(sumScore);
    return 0;
}

void getWinner(int sumScore[5])
{
    int max = 0, winner;
    for (int i = 0; i < 5; i++)
    {
        if (sumScore[i] > max)
        {
            winner = i + 1;
            max = sumScore[i];
        }
    }
    printf("%d %d\n", winner, max);
}