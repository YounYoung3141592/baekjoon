#include <stdio.h>
#include <math.h>

// 문제를 이해를 못하겠냐... 이거 뭐임?

void getCard(double);
int main()
{
    double card;
    scanf("%lf", &card);
    while (card != 0.00)
    {
        getCard(card);
        scanf("%lf", &card);
    }
    return 0;
    // while (card != 0.00)
    // {
    //     printf("%lf\n", card);
    //     scanf("%lf", &card);
    // }
}

void getCard(double c)
{
    double sum = 0.5;
    int n = 1;
    while (c > sum)
    {
        // n++;
        // double temp = round(100000000 / (n + 1)) / 100000000.0;
        // sum += temp;

        // printf("temp : %.3lf\n", temp);
        // printf("n : %d, c : %.3lf, sum : %.3lf\n", n, c, sum);

        n++;
        sum += 1.0 / (n + 1);
    }
    printf("%d card(s)\n", n);
    return;
}