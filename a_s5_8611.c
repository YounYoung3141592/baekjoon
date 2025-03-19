#include <stdio.h>
#include <stdlib.h>

char *zinbup(int, int);
int isitPalindrome(char *);
int main()
{
    // 입력 처리 : 최대 10의 1000승
    char n[1005];
    int palindromeCount = 0;
    scanf("%s", n);

    // 입력 테스트
    // printf("%s", n);

    // zinbup test
    // for (int i = 2; i <= 10; i++)
    // {
    //     char *result = zinbup(n, i);
    //     printf("%d진법 : %s\n", i, result);
    //     // i진법으로 나타낸 n을 구한다.
    //     if (isitPalindrome(result) == 1)
    //     {
    //         printf("%d %s\n", i, result);
    //         palindromeCount++;
    //     }
    // }
    // if (palindromeCount == 0)
    // {
    //     printf("NIE");
    // }
    // return 0;
    int maxIndex = 0;
    while (n[maxIndex] != '\0')
    {
        maxIndex++;
    }
    maxIndex--;
}

char *zinbup(int n, int base)
{
    // // int log_jinsu_n = 0, tempn = n;
    // // while (pow(jinsu, log_jinsu_n) <= n)
    // // {
    // //     log_jinsu_n++; // i^login >n인 최소 login
    // // }
    // // char *result = (char *)malloc(sizeof(char) * (log_jinsu_n + 1));
    // // for (int i = log_jinsu_n - 1; i >= 0; i++)
    // // {
    // //     result[log_jinsu_n - 1 - i] = '0' + (tempn / (int)pow(jinsu, i));
    // //     tempn %= (int)pow(jinsu, i);
    // // }
    // // result[log_jinsu_n] = '\0';
    // // return result;
    // // 챗지피티 제안을 바탕으로, char* result를 점점 확장하는 방식으로 저장하려함
    // int temp = n, digits = 0;
    // // n이 0일경우
    // if (n == 0)
    // {
    //     char *result = (char *)malloc(2 * sizeof(char));
    //     result[0] = '0';
    //     result[1] = '\0';
    //     return result;
    // }
    // while (temp > 0)
    // {
    //     temp /= base;
    //     digits++;
    // }
    // char *result = (char *)malloc((digits + 1) * sizeof(char));
    // result[digits] = '\0'; // NULL 문자 삽입
    // // 변환 작업
    // for (int i = digits - 1; i >= 0; i--)
    // {
    //     int remainder = n % base;
    //     if (remainder < 10)
    //         result[i] = '0' + remainder; // 0~9는 숫자로 처리
    //     else
    //         result[i] = 'A' + (remainder - 10); // 10 이상은 A, B, C...
    //     n /= base;
    // }
    // return result;
    char *result;
    int tempN = n, maxIndex = 0;
    while (tempN >= base)
    {
        tempN /= base;
        maxIndex++;
    }
    maxIndex++;
    result = (char *)malloc(sizeof(char) * (maxIndex + 1));
    result[maxIndex] = '\0';
    for (int i = maxIndex - 1; i >= 0; i--)
    {
        result[i] = n % base + 48;
        n /= base;
    }
    return result;
}

int isitPalindrome(char *zinbup)
{
    int maxIndex = 0;
    while (zinbup[maxIndex] != '\0')
    {
        maxIndex++;
    }
    maxIndex--;
    // test
    // printf("maxINdex : %d\n", maxIndex);
    for (int i = 0; i <= maxIndex / 2; i++)
    {
        if (zinbup[i] != zinbup[maxIndex - i])
        {
            return 0;
        }
    }
    return 1;
}