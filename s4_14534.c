#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
n개의 길이가 각각 l1, l2 ... ln인 문자열이 주어지고,
각각의 문자열에 대해 가능한 모든 문자의 재배열을 조건에 맞게나열한다.
*/

void printCases(char *, int, int);
void swap(char *, int, int);
int main()
{
    // 문제 입력 처리
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char string[6]; // 최대 5문자 + 널 문자 저장 공간 포함
        scanf("%s", string);
        // 문제 입력 확인
        printf("Case # %d:\n", i);
        // printf("%s\n", string);
        // if (i == 0)
        // {
        //     printf("Case # %d:\n", i);
        // }
        // else
        // {
        //     printf("\nCase # %d:", i);
        // }
        int maxIndex = 0;
        while (string[maxIndex] != '\0')
        { // 문자열의 길이(최대 인덱스+1)를 구한다.
            maxIndex++;
        }
        printCases(string, 0, maxIndex - 1); // 모든 문자의 재배열을 출력한다.
    }
    return 0;
}
void printCases(char *string, int start, int end)
{
    // printf("fun now : %s, start : %d, end : %d\n", string, start, end);
    if (end == start)
    {
        printf("%s\n", string);
    }
    else
    { // end>start
        printCases(string, start + 1, end);
        for (int i = start + 1; i <= end; i++)
        {
            char str2[6];
            strcpy(str2, string);
            swap(str2, start, i);
            printCases(str2, start + 1, end);
        }
    }
}
void swap(char *string, int a, int b)
{
    // 자리 바꾸기 + 조정
    if (b - a == 1)
    { // 조정할 필요가 없는 경우
        char temp = string[a];
        string[a] = string[b];
        string[b] = temp;
    }
    else
    { // b>a
        char tempB = string[b];
        for (int i = b; i > a; i--)
        {
            string[i] = string[i - 1];
        }
        string[a] = tempB;
    }
}

// int main()
// {
//     // 문제 입력 처리
//     int n;
//     scanf("%d", &n);
//     char string[6]; // 최대 5문자 + 널 문자 저장 공간 포함
//     scanf("%s", string);
//     int maxIndex = 0;
//     while (string[maxIndex] != '\0')
//     { // 문자열의 길이(최대 인덱스+1)를 구한다.
//         maxIndex++;
//     }
//     maxIndex--;
//     for (int i0 = 0; i0 <= maxIndex;i0++){

//     }
// }