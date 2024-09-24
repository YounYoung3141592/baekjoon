#include <stdio.h>

int main()
{
    int n, jalitsu[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
           index = 0;
    scanf("%d", &n);
    while (n > 0)
    {
        jalitsu[index++] = n % 10;
        // printf("n : %d jalitsu : %d\n", n, jalitsu[index - 1]);
        n /= 10;
    }
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d ", jalitsu[i]);
    // }
    // printf("\n");
    for (int i = 0; i < 10; i++)
    {
        int j = i - 1;
        while ((j >= 0) && (jalitsu[j] > jalitsu[j + 1]))
        {
            int temp = jalitsu[j];
            jalitsu[j] = jalitsu[j + 1];
            jalitsu[j + 1] = temp;
            j--;
        }
    }
    // for (int i = 0; i < index; i++)
    // {
    //     printf("%d", jalitsu[i]);
    // }
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%d", jalitsu[i]);
    }
    return 0;
}