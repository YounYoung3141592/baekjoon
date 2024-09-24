#include <stdio.h>

void print(int, char a[80]);
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char temp[80];
        int index;
        scanf("%d %s", &index, temp);
        print(index - 1, temp); // 배열에서의 0부터 시작하는 인덱스에 맞추기 위함
    }
    return 0;
}

void print(int index, char string[80])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (i != index)
        {
            printf("%c", string[i]);
        }
    }
    printf("\n");
}