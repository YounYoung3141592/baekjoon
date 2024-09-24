#include <stdio.h>
#include <stdlib.h>

int getLength(char s[]);
void checkSameAndPrint(char **, int, int);
int main()
{
    int n;
    scanf("%d", &n);
    char **file = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        file[i] = (char *)malloc(sizeof(char) * 50);
        scanf("%s", file[i]);
    }
    char *pattern = (char *)malloc(sizeof(char) * n);
    pattern = file[0];
    // printf("%s", pattern);
    // return 0;
    int length = getLength(file[0]);
    for (int i = 0; i < length; i++)
    {
        checkSameAndPrint(file, n, i);
    }
}

int getLength(char string[])
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}

void checkSameAndPrint(char **file, int num, int index)
{
    char temp = file[0][index];
    for (int i = 1; i < num; i++)
    {
        if (temp != file[i][index])
        {
            printf("?");
            return;
        }
    }
    printf("%c", temp);
    return;
}