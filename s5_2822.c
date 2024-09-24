#include <stdio.h>

// int main()
// {
//     int score[8];
//     for (int i = 0; i < 8; i++)
//     {
//         scanf("%d", &score[i]);
//     }
//     // 배운거 활용할 겸 insertion sort로 해보자
//     for (int i = 1; i < 8; i++)
//     {
//         int j = i - 1;
//         while ((j >= 0) && (score[j] > score[j + 1]))
//         {
//             int temp = score[j];
//             score[j] = score[j + 1];
//             score[j + 1] = temp;
//             j--;
//         }
//     }
//     for (int i = 0; i < 8; i++)
//     {
//         printf("%d ", score[i]);
//     }
//     return 0;
// }

struct score
{
    int score;
    int index;
};
void exchange(struct score s[8], int, int);
int main()
{
    struct score score[8];
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &score[i].score);
        score[i].index = i + 1;
    }
    // exchange(score, 0, 7);         exchange실험용
    // for (int i = 0; i < 8; i++)
    // {
    //     printf("%d ", score[i]);
    // }
    for (int i = 0; i < 8; i++)
    {
        int j = i - 1;
        while ((j >= 0) && (score[j].score > score[j + 1].score))
        {
            exchange(score, j, j + 1);
            j--;
        }
    }
    int sum = 0;
    for (int i = 7; i > 2; i--)
    {
        sum += score[i].score;
    }
    printf("%d\n", sum);
    int index[5];
    for (int i = 0; i < 5; i++)
    {
        index[i] = score[7 - i].index;
    }
    for (int i = 0; i < 5; i++)
    {
        int j = i - 1;
        while ((j >= 0) && (index[j] > index[j + 1]))
        {
            int temp = index[j];
            index[j] = index[j + 1];
            index[j + 1] = temp;
            j--;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", index[i]);
    }
}

void exchange(struct score s[8], int a, int b)
{
    struct score temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}