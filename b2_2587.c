#include <stdio.h>

int getAverage(int a[5]);
int main()
{
    int nums[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &nums[i]);
    }
    for (int i = 1; i < 5; i++)
    {
        int j = i - 1;
        while ((j >= 0) && (nums[j] > nums[j + 1]))
        {
            int temp = nums[j];
            nums[j] = nums[j + 1];
            nums[j + 1] = temp;
            j--;
        }
    }
    printf("%d\n%d", getAverage(nums), nums[2]);
    return 0;
}

int getAverage(int a[5])
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += a[i];
    }
    return sum / 5;
}