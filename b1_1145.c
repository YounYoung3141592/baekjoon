#include <stdio.h>

// input : 다섯개의 자연수
// output : 다섯개의 자연수 중 적어도 세개로 나누어지는 가장 작은 자연수.
// 반례 : tc1처럼 한 수가 다른 수의 배수이고, 또 다른수는

int getBasu3(int, int, int);
int getBasu5(int n[5]);
int getBasu(int, int);
int main()
{
    int num[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num[i]);
    }
    int min = getBasu3(num[0], num[1], num[2]);
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                int temp = getBasu3(num[i], num[j], num[k]);
                min = (temp > min) ? min : temp;
            }
        }
    }
    printf("%d", min);
    return 0;
}
// 그럼 일단 다섯개의 배수를 구해서 두개의 배수가 가장 큰 한 쌍을 찾고 그 배수로 다섯개의 배수를 나누면 되는거 아닌가?
// int main()
// {
//     int num[5];
//     for (int i = 0; i < 5; i++)
//     {
//         scanf("%d", &num[i]);
//     }
//     int basu5 = getBasu5(num);
//     int maxBasu2 = 0;
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = i; j < 5; j++)
//         {
//             int temp = getBasu(num[i], num[j]);
//             maxBasu2 = (maxBasu2 > temp) ? maxBasu2 : temp;
//         }
//     }
//     printf("%d", basu5 / maxBasu2);
// }

// 함수 검사용
//  int main()
//  {
//      int num[5];
//      for (int i = 0; i < 5; i++)
//      {
//          scanf("%d", &num[i]);
//      }
//      printf("%d, %d : %d\n", num[0], num[1], getBasu(num[0], num[1]));
//      printf("all : %d", getBasu5(num));
//      return 0;
//  }

int getBasu3(int a, int b, int c)
{
    // 2개
    //  int mul = a * b;
    //  int big = a;
    //  int maxYaksu = 1;
    //  for (int i = 2; i <= big; i++)
    //  {
    //      if ((a % i == 0) && (b % i == 0))
    //      {
    //          maxYaksu = i;
    //      }
    //  }
    //  return mul / maxYaksu;
    int ab = getBasu(a, b);
    int abc = getBasu(ab, c);
    return abc;
}

int getBasu(int a, int b)
{
    int mul = a * b;
    int big = a;
    int maxYaksu = 1;
    for (int i = 2; i <= big; i++)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            maxYaksu = i;
        }
    }
    return mul / maxYaksu;
}

int getBasu5(int n[5])
{
    int mul = n[0] * n[1] * n[2] * n[3] * n[4];
    int big = 0, maxYaksu = 1;
    for (int i = 0; i < 5; i++)
    {
        big = (big > n[i]) ? big : n[i];
    }
    for (int i = 2; i <= big; i++)
    {
        if ((n[0] % i == 0) && (n[1] % i == 0) && (n[2] % i == 0) && (n[3] % i == 0) && (n[4] % i == 0))
        {
            maxYaksu = i;
        }
    }
    return mul / maxYaksu;
}