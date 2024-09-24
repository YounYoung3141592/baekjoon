#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *aray = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &aray[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        while ((j >= 0) && (aray[j] > aray[j + 1]))
        {
            int temp = aray[j];
            aray[j] = aray[j + 1];
            aray[j + 1] = temp;
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", aray[i]);
    }
    return 0;
}