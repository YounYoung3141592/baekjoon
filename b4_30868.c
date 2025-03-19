#include <stdio.h>

int main()
{
    int n, vote;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vote);
        while (vote >= 5)
        {
            printf("++++ ");
            vote -= 5;
        }
        for (int i = 0; i < vote; i++)
        {
            printf("|");
        }
        printf("\n");
    }
    return 0;
}