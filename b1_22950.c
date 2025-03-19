#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
길이가 n인 어떤 이진수가 2^k로 나누어지는지 구하여라.

시간 초과면 납득했을텐데 왜 틀렸지?
*/
// int main()
// {
//     int n, k;
//     long long m = 0;
//     scanf("%d", &n);
//     char *originIzinsu = (char *)malloc(sizeof(char) * n);
//     scanf("%s", originIzinsu);
//     scanf("%d", &k);
//     // for (int i = 0; i < n; i++)
//     // {
//     //     printf("%d : %c\n", i, originIzinsu[i]);
//     // }
//     for (int i = 0; i < n; i++)
//     {
//         // m += (int)pow(2, n - i - 1) * (originIzinsu[i] - 48);
//         if (originIzinsu[i] == '1')
//         {
//             // printf("i : %d\n", i);
//             m += (long long)pow(2, (n - i - 1));
//         }
//     }
//     // printf("%s\n%d\n", originIzinsu, m);
//     // long long twoSquareK = (long long)pow(2, k);
//     long long twoSquareK = (1LL << k);
//     // if (m % 2 == 1)
//     // {
//     //     // 이때, m은 홀수이므로 그 어떤 2^k의 배수도 될 수 없다.
//     //     printf("NO");
//     // }
//     // else if (m < twoSquareK)
//     // {
//     //     // 2^k보다 작은 m은 2^k의 배수가 될 수 없다.
//     //     printf("NO");
//     // }
//     // else
//     // {
//     //     if (m % twoSquareK == 0)
//     //     {
//     //         printf("YES");
//     //     }
//     //     else
//     //     {
//     //         printf("NO");
//     //     }
//     // }
//     if (m == 0)
//     {
//         printf("NO");
//     }
//     else if (m % twoSquareK == 0)
//     {
//         printf("YES");
//     }
//     else
//     {
//         // printf("%d는 %lld로 나누어질 수 없음\n", m, twoSquareK);
//         printf("NO");
//     }
//     return 0;
// }

int isitAll0(char *, int, int, int);
int main()
{
    int n, k;
    scanf("%d", &n);
    char *izinsu = (char *)malloc(sizeof(char) * (n + 1));
    scanf("%s", izinsu);
    scanf("%d", &k);
    // 방법1 : 이진수에 해당하는 10진수 만들어 나누기기
    //  for (int i = 0; i < n; i++)
    //  {
    //      printf("%c", izinsu[i]);
    //  }
    //  printf("\n");
    //  if (isitAll0(izinsu, n))
    //  { // 전부 다 0이면 1을 반환한다.
    //      printf("NO");
    //      return 0;
    //  }
    //  if (n > k)
    //  {
    //      for (int i = n - k; i < n; i++)
    //      {
    //          if (izinsu[i] == '1')
    //          {
    //              printf("NO");
    //              return 0;
    //          }
    //      }
    //  }
    //  else if (k == 0)
    //  {
    //      printf("YES");
    //      return 0;
    //  }
    //  else if (k == n)
    //  {
    //      if (izinsu[0] == '1')
    //      {
    //          for (int i = 1; i < n; i++)
    //          {
    //              if (izinsu[i] == '1')
    //              {
    //                  printf("NO");
    //                  return 0;
    //              }
    //          }
    //      }
    //      else
    //      {
    //          printf("NO");
    //          return 0;
    //      }
    //  }
    //  else
    //  {
    //      printf("NO");
    //      return 0;
    //  }
    //  printf("YES");
    //  return 0;

    // 방법2 : 1~k-1번째 자리 0인지 검사하기기
    //  if (isitAll0(izinsu, n))
    //  { // case b : m이 전부 0일 경우
    //      // m이 전부 0이면 참이다.
    //      free(izinsu);
    //      printf("NO");
    //      return 0;
    //  }
    //  if (n < k)
    //  {
    //      // 2^n < 2^k이기 때문에, m은 2^k의 배수일 수 없다.
    //      free(izinsu);
    //      printf("NO");
    //      return 0;
    //  }
    //  if (k == 0)
    //  {
    //      free(izinsu);
    //      printf("YES");
    //      return 0;
    //  }
    //  for (int i = n - k; i < n; i++)
    //  {
    //      if (izinsu[i] == '1')
    //      {
    //          free(izinsu);
    //          printf("YES");
    //          return 0;
    //      }
    //  }
    //  free(izinsu);
    //  printf("YES");
    //  return 0;

    // 방법3 : 1. 1~k-1번째 자리가 존재하며, 모두 0인지 확인
    //         2. k번째 자리부터가 존재하며, 1이 하나라도 존재하는지 확인
    // if (n - k > 0)
    // { // 방법3-2 중 k번째 자리가 존재함을 검사
    //     if (isitAll0(izinsu, n, 0, n - k - 1) == 0)
    //     {                                               // 방법3-2 중 1이 하나라도 존재하는지 검사
    //         if (isitAll0(izinsu, n, n - k, n - 1) == 1) // 방법 3-1 중 모두 0인지 검사
    //         {
    //             free(izinsu);
    //             printf("YES");
    //             return 0;
    //         }
    //     }
    // }

    // 가설 : 0은 yes판정이다.
    if (isitAll0(izinsu, n, 0, n - 1))
    { // case b : m이 전부 0일 경우
        // m이 전부 0이면 참이다.
        free(izinsu);
        printf("YES");
        return 0;
    }
    if (n - k > 0)
    {                                               // 방법3-2 중 k번째 자리가 존재함을 검사
        if (isitAll0(izinsu, n, n - k, n - 1) == 1) // 방법 3-1 중 모두 0인지 검사
        {
            free(izinsu);
            printf("YES");
            return 0;
        }
    }
    free(izinsu);
    printf("NO");
    return 0;
}

int isitAll0(char *izinsu, int n, int start, int end)
{
    int result = 1;
    for (int i = start; i <= end; i++)
    {
        if (izinsu[i] == '1')
        {
            result = 0;
            break;
        }
    }
    return result;
}