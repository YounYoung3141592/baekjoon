#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 최소 수 : 텅빈 세로 수/텅빈 가로 수 둘 중 큰거
int getRow(char **, int, int);
int getColumn(char **, int, int);
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char **castle = (char **)malloc(sizeof(char *) * n);

    // 할당
    for (int i = 0; i < n; i++)
    {
        castle[i] = (char *)malloc(sizeof(char) * m);
        scanf("%s", castle[i]);
    }
    int *row = (int *)malloc(sizeof(int) * n);
    int *column = (int *)malloc(sizeof(int) * m);

    //
    for (int i = 0; i < n; i++)
    {
        row[i] = getRow(castle, i, m);
    }
    for (int i = 0; i < m; i++)
    {
        column[i] = getColumn(castle, i, n);
    }

    int countRow = 0, countColumn = 0;
    for (int i = 0; i < n; i++)
    {
        if (row[i] == 0)
        {
            countRow++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (column[i] == 0)
        {
            countColumn++;
        }
    }

    printf("%d", (countRow > countColumn) ? countRow : countColumn);
    return 0;

    // printf("row :");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", row[i]);
    // }
    // printf("\ncolumn : ");
    // for (int i = 0; i < m; i++)
    // {
    //     printf("%d ", column[i]);
    // }
    // return 0;
}

int getRow(char **c, int index, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (c[index][i] == 'X')
        {
            return 1;
        }
    }
    return 0;
}

int getColumn(char **c, int index, int n)
{
    for (int i = 0; i < n; i++)
    {
        char temp = c[i][index];
        if (c[i][index] == 'X')
        {
            return 1;
        }
    }
    return 0;
}