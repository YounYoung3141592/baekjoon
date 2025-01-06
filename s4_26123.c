#include <stdio.h>
#include <stdlib.h>

void sort(int *, int);
void swap(int *, int *);
int laser(int *, int *, int *);
void quickSort(int *aray, int start, int end);
int findMax(int *, int);
int main()
{
    int building, days;
    scanf("%d %d", &building, &days);
    int *height = (int *)malloc(sizeof(int) * building);
    for (int i = 0; i < building; i++)
    {
        scanf("%d", &height[i]);
    }

    // sort(height, building); // buildingHeights를 내림차순으로 정렬
    // quickSort(height, 0, building - 1);
    // for (int i = 0; i < building; i++)
    // {
    //     printf("%d ", height[i]);
    // }
    int maxHeight = findMax(height, building), indexNow = 0;
    long int laserSum = 0;
    // for (int i = 0; i < days; i++)
    // {
    //     laserSum += laser(height, &maxHeightIndex, &maxHeight);
    //     if (maxHeight <= 0)
    //     {
    //         printf("%ld", laserSum);
    //         return 0;
    //     }
    // }
    if (maxHeight >= days)
    {
        // case1
        // while (maxHeight > maxHeight - days)
        // {
        //     laserSum += height[indexNow++] - maxHeight + days;
        // }
        for (int i = 0; i < building; i++)
        {
            if (height[i] > maxHeight - days)
            {
                laserSum += height[i] - maxHeight + days;
            }
        }
    }
    else
    {
        // case2
        // while ((height[indexNow] > 0) && (indexNow < building))
        // {
        //     laserSum += height[indexNow++];
        // }
        for (int i = 0; i < building; i++)
        {
            laserSum += height[indexNow++];
        }
    }
    printf("%ld", laserSum);
    return 0;
}

int findMax(int aray[], int maxIndex)
{
    int max = -1;
    for (int i = 0; i < maxIndex; i++)
    {
        max = (aray[i] > max) ? aray[i] : max;
    }
    return max;
}
void sort(int *aray, int maxIndex)
{
    // 삽입정렬하면 시간초과임
    // for (int i = 1; i < maxIndex; i++)
    // {
    //     int index = i;
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (aray[index - 1] > aray[index])
    //         {
    //             swap(&aray[i], &aray[j]);
    //             index--;
    //         }
    //     }
    // }
    // for (int i = 1; i < maxIndex; i++)
    // {
    //     int value = aray[i];
    //     int indexOfValue = i;
    //     while ((aray[indexOfValue - 1] < value) && (indexOfValue > 0))
    //     {
    //         swap(&aray[indexOfValue], &aray[indexOfValue - 1]);
    //         indexOfValue--;
    //     }
    // }
}

void quickSort(int *aray, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int key = start, i = start + 1, j = end, temp;
    while (i <= j)
    {
        while (i <= end && aray[i] >= aray[key])
            i++;
        while (j > start && aray[j] <= aray[key])
            j--;
        if (i > j)
            swap(&aray[key], &aray[j]);
        else
            swap(&aray[i], &aray[j]);
    }
    quickSort(aray, start, j - 1);
    quickSort(aray, j + 1, end);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int laser(int *height, int *maxHeightIndex, int *maxHeight)
{
    // 시간초과
    //  while (height[*maxHeightIndex + 1] == *maxHeight)
    //  {
    //      (*maxHeightIndex)++;
    //  }
    //  for (int i = 0; i < (*maxHeightIndex) + 1; i++)
    //  {
    //      height[i]--;
    //  }
    //  (*maxHeight)--;
    // return (*maxHeightIndex) + 1;
}
