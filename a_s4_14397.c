#include <stdio.h>
#include <stdlib.h>

/*
해변 구하기
n * m 넓이의 지도가 있고, 현재 인덱스가 i,j일때,
(i+1,j-1), (i+1,j), (i,j+1)와 i,j가 같은지 비교하여 다른 경우를 센다.

예외 : j 인덱스가 0, n-1인 경우 / 마지막 줄인 경우
*/
void plusBeach(int *, char **, int, int);
int main()
{
    // 입력 처리
    int n, m, beach = 0;
    scanf("%d %d", &n, &m);
    char **map = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        map[i] = (char *)malloc(sizeof(char) * m);
        scanf("%s", map[i]);
    }
    // 입력 확인
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         printf("%c", map[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char tempMap = map[i][j];
            // 1. 옆에거랑 비교
            if (j < m - 1)
            {
                if (tempMap != map[i][j + 1])
                {
                    plusBeach(&beach, map, i, j);
                }
            }

            if (i < n - 1)
            {
                if (j == 0)
                {
                    if (i % 2 == 0)
                    {
                        if (tempMap != map[i + 1][j])
                        {
                            plusBeach(&beach, map, i, j);
                        }
                    }
                    else
                    {
                        if (tempMap != map[i + 1][j])
                        {
                            plusBeach(&beach, map, i, j);
                        }
                        if (tempMap != map[i + 1][j + 1])
                        {
                            plusBeach(&beach, map, i, j);
                        }
                    }
                }
                else if (j == m - 1)
                {
                    if (i % 2 == 0)
                    {
                        if (tempMap != map[i + 1][j - 1])
                        {
                            plusBeach(&beach, map, i, j);
                        }
                        if (tempMap != map[i + 1][j])
                        {
                            plusBeach(&beach, map, i, j);
                        }
                    }
                    else
                    {
                        if (tempMap != map[i + 1][j])
                        {
                            plusBeach(&beach, map, i, j);
                        }
                    }
                }
                else
                {
                    // 일반적인 경우

                    // 얘네도 i의 홀짝여부에 따라 분리해야함
                    //   2. 밑에거 왼쪽이랑 비교
                    //  if (tempMap != map[i + 1][j - 1])
                    //  {
                    //      plusBeach(&beach, map, i, j);
                    //  }
                    //  // 3. 밑에거 오른쪽이랑 비교
                    //  if (tempMap != map[i + 1][j])
                    //  {
                    //      plusBeach(&beach, map, i, j);
                    //  }
                    if (i % 2 == 0)
                    {
                        // 왼쪽 : j-1
                        if (tempMap != map[i + 1][j - 1])
                        {
                            plusBeach(&beach, map, i, j);
                        }
                        // 오른쪽 : j
                        if (tempMap != map[i + 1][j])
                        {
                            plusBeach(&beach, map, i, j);
                        }
                    }
                    else
                    {
                        // 왼쪽 : j
                        if (tempMap != map[i + 1][j])
                        {
                            plusBeach(&beach, map, i, j);
                        }
                        // 오른쪽 : j+1
                        if (tempMap != map[i + 1][j + 1])
                        {
                            plusBeach(&beach, map, i, j);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", beach);
    return 0;
}

void plusBeach(int *beach, char **map, int i, int j)
{
    *beach = *beach + 1;

    // 디버깅용 코드
    // printf("%c(%d,%d)\n", map[i][j], i, j);
}