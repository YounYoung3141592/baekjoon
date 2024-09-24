#include <stdio.h>
#include <stdlib.h>

int printMin(int aray[], int);
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        int *tempAray = (int *)malloc(temp * sizeof(int));
        for (int j = 0; j < temp; j++)
        {
            scanf("%d", &tempAray[j]);
        }
        // for (int j = 0; j < temp; j++) 입력 확인용
        // {
        //     printf("%d ", tempAray[j]);
        // }
        // printf("\n");
        printMin(tempAray, temp);
    }
    return 0;
}

int printMin(int aray[], int length)
{
    int min = 100, max = 0;
    for (int i = 0; i < length; i++)
    {
        min = (aray[i] < min) ? aray[i] : min;
        max = (max < aray[i]) ? aray[i] : max;
    }
    printf("%d\n", (max - min) * 2);
}