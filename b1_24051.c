#include <stdio.h>
#include <stdlib.h>

// void swap(int a[], int)
// int main()
// {
//     int n, k, count = 0;
//     scanf("%d %d", &n, &k);
//     int *aray = (int *)malloc(sizeof(int) * n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &aray[i]);
//     }
//     // 입력엔 문제 없음.
//     // printf("n : %d, k : %d\n", n, k);
//     // for (int i = 0; i < n; i++)
//     // {
//     //     printf("%d ", aray[i]);
//     // }
//     for (int i = 1; i < n; i++)
//     {
//         int temp = i - 1;
//         while (aray[temp] > aray[temp + 1])
//         {
//             swap(aray, temp + 1);
//             count++;
//             if (count == k)
//             {
//                 printf("%d", aray[i]);
//                 return 0;
//             }
//             temp--;
//         }
//     }
//     // for (int i = 0; i < n; i++)
//     // {
//     //     printf("%d ", aray[i]);
//     // }
//     printf("-1");
//     return 0;
// }
// void swap(int a[], int i)
// {
//     int temp = a[i - 1];
//     a[i - 1] = a[i];
//     a[i] = temp;
// }
int main(int argc, char const *argv[])
{
    int n, k, count = 0;
    scanf("%d %d", &n, &k);
    int *aray = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &aray[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int temp = i - 1;
        int newItem = aray[i];
        while (newItem < aray[temp])
        {
            aray[temp + 1] = aray[temp];
            temp--;
            count++;
            if (count == k)
            {
                printf("%d", aray[temp + 1]);
                return 0;
            }
        }
        if (temp + 1 != i)
        {
            aray[temp + 1] = newItem;
            count++;
            if (count == k)
            {
                printf("%d", newItem);
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}
