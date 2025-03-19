#include <stdio.h>
#include <stdlib.h>

/*
투박하게 그냥 세보고, 시간초과 나면 그땐 원문 활용해서 짧게 구현해야 할듯
*/
// 뭐지 왜 평범하게 틀렸지??
int findMax(int *);
int main()
{
    int n;
    scanf("%d", &n);
    char *logosong = (char *)malloc(sizeof(char) * (n + 1));
    char *temp;
    // scanf("%s", logosong);
    //  printf("%s\n", logosong);
    // scanf("%[^\n]s", logosong);
    getchar();
    fgets(logosong, n + 1, stdin);
    // printf("%s\n", logosong);
    int countAlphabet[26];
    for (int i = 0; i < 26; i++)
    {
        countAlphabet[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if ((logosong[i] >= 97) && (logosong[i] <= 122))
        {
            countAlphabet[logosong[i] - 97]++;
        }
    }
    printf("%d", findMax(countAlphabet));
    return 0;
}

int findMax(int aray[26])
{
    int max = -1;
    for (int i = 0; i < 26; i++)
    {
        if (max < aray[i])
        {
            max = aray[i];
        }
    }
    return max;
}