#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
powers of integers
n의 p제곱 계산
출력 : 한 줄에 70글자씩, 마지막 줄은 더 짧게
*/

struct partOfNum
{
    int num; // 00000~99999로 유지되도록 함.
    int isitOver99999;
    int olimsu;
    struct partOfNum *frontDigit;
    struct partOfNum *backDigit;
};

void power(struct partOfNum *, struct partOfNum *, int);
void NewPartOfNum(struct partOfNum **, struct partOfNum **, int);
void initPartOfNum(struct partOfNum *);
void printNum70(struct partOfNum *);
// long long int multiple(struct partOfNum *, int);
// void addOlimsu(struct partOfNum *);
void multipleSum(struct partOfNum **, struct partOfNum **);
int main()
{
    int n, p;
    scanf("%d %d", &n, &p);
    struct partOfNum *head = NULL, *tail = NULL;
    NewPartOfNum(&head, &tail, n); // n을 (필요하다면)쪼개어 partofnum에 할당한다.
    // test NewPartOfNum
    // printf("original n :%d\n", n);
    // printNum70(head);
    // test NewPartOfNum,printNum70
    // struct partOfNum *head = NULL, *tail = NULL;
    // int num = 123456789;
    // NewPartOfNum(&head, &tail, num);
    // printNum70(head);

    for (int i = 0; i < p - 1; i++)
    {
        // test power
        // struct partOfNum *index = head;
        // printf("\n**power : %d\n", i);
        // while (index != NULL)
        // {
        //     printf("num : %d, olimsu : %d\n", index->num, index->olimsu);
        //     index = index->backDigit;
        // }
        power(head, tail, n);
        multipleSum(&head, &tail);
    }
    // test power
    // struct partOfNum *index = head;
    // while (index != NULL)
    // {
    //     printf("num : %d, olimsu : %d\n", index->num, index->olimsu);
    //     index = index->backDigit;
    // }
    printNum70(head);
}

void NewPartOfNum(struct partOfNum **head, struct partOfNum **tail, int n)
{
    // while (n > 0)
    // {
    //     int first5 = n % 100000;
    //     struct partOfNum *number = (struct partOfNum *)malloc(sizeof(struct partOfNum) * 1);
    //     number->backDigit = NULL;
    //     if (tail == NULL)
    //     {
    //         tail = number;
    //     }
    // }
    while (n > 0)
    {
        struct partOfNum *number = (struct partOfNum *)malloc(sizeof(struct partOfNum) * 1);
        if (*tail == NULL)
        {
            *tail = number; // 완전 초기 생성
            // printf("tail 함수 할당 num : %d\n", (*tail)->num);
            number->backDigit = NULL;
        }
        else
        {
            number->backDigit = *head;
            (*head)->frontDigit = number;
        }
        initPartOfNum(number);
        *head = number;
        number->num = n % 100000;
        n /= 100000;
    }
}

void initPartOfNum(struct partOfNum *number)
{
    number->frontDigit = NULL;
    number->isitOver99999 = 0;
    number->olimsu = 0;
}

void printNum70(struct partOfNum *head)
{
    struct partOfNum *temp = head;
    int count = 0, headJalitsu;
    if (temp->num / 10000 > 0)
    {
        // 5
        headJalitsu = 5;
    }
    else if (temp->num / 1000 > 0)
    {
        headJalitsu = 4;
    }
    else if (temp->num / 100 > 0)
    {
        headJalitsu = 3;
    }
    else if (temp->num / 10 > 0)
    {
        headJalitsu = 2;
    }
    else
    {
        headJalitsu = 1;
    }
    printf("%d", temp->num);
    // printf("num : %d, count : %d\n", temp->num, count);
    count += headJalitsu;
    temp = temp->backDigit;
    while (temp != NULL)
    {
        if (count == 0)
        {
            // 한 줄의 맨 처음
            printf("%05d", temp->num);
            // printf("num : %d, count : %d\n", temp->num, count);
            count += headJalitsu;
        }
        else if (count > 65)
        {
            // 끝자락에 걸린 수가 00000이여도 n/5-n개 출력되도록 로직 짜야함.
            //  // 한 줄의 끝 : count범위 66~70
            //  int haveToPrintNumOver = (int)pow(10, count - 65);
            //  // 예를들어 3자리만 뽑아내야하면 10^(67-65)=100
            //  printf("%d", temp->num / haveToPrintNumOver);
            //  printf("\n"); // 줄 바꿈
            //  printf("%d", temp->num % haveToPrintNumOver);
            //  // test printNum70
            //  // printf("num : %d, count : %d\n", temp->num, count);
            //  // printf("\n"); // 줄 바꿈
            //  // printf("num : %d, count : %d\n", temp->num, count);
            //  count = headJalitsu;

            int haveToPrintNumOver = (int)pow(10, count - 65);
            switch (headJalitsu)
            {
            case 5:
                // count==70,0자리 인쇄 필요
                printf("\n"); // 줄 바꿈
                break;
            case 4:
                // count==69,1자리 인쇄 필요
                printf("%01d", temp->num / 10000);
                printf("\n"); // 줄 바꿈
                printf("%04d", temp->num % 10000);
                break;
            case 3:
                // count==68,2자리 인쇄 필요
                printf("%02d", temp->num / 1000);
                printf("\n"); // 줄 바꿈
                printf("%03d", temp->num % 1000);
                break;
            case 2:
                // count==67,3자리 인쇄 필요
                printf("%03d", temp->num / 100);
                printf("\n"); // 줄 바꿈
                printf("%02d", temp->num % 100);
                break;
            case 1:
                // count==66,4자리 인쇄 필요
                printf("%04d", temp->num / 10);
                printf("\n"); // 줄 바꿈
                printf("%01d", temp->num % 10);
                break;
            }
            count = headJalitsu;
        }
        else
        {
            // 한 줄의 중간
            printf("%05d", temp->num);

            // test printNum70
            // printf("num : %d, count : %d\n", temp->num, count);
            count += 5;
        }
        temp = temp->backDigit;
    }
    // 여기서 head의 num이 5자리가 아닐 가능성을 고려해야함.
    //  while (temp != NULL)
    //  {
    //      printf("%d", temp->num);
    //      if (count > 14)
    //      {
    //          printf("\n");
    //          count = 1;
    //      }
    //      else
    //      {
    //          count++;
    //      }
    //      // chatGPT 추천 코드 : 내건 왜 틀린거지?
    //      // if (temp->backDigit == NULL)
    //      //     printf("%d", temp->num);
    //      // else
    //      //     printf("%05d", temp->num);
    //      // count += 5;
    //      // if (count >= 70)
    //      // {
    //      //     printf("\n");
    //      //     count = 0;
    //      // }
    //      temp = temp->backDigit;
    //  }
}

void power(struct partOfNum *head, struct partOfNum *tail, int n)
{
    // printf("power 함수 수행\n");
    struct partOfNum *index = tail;
    long long int result;

    // if (tail == NULL)
    // {
    //     printf("tail, index가 null\n");
    // }
    while (index != NULL)
    {
        // // printf("multiple 함수 수행\n");
        // result = multiple(index, n);
        // // multiple함수가 수행하는것 : index에 해당하는 자릿수 5개에 n을 곱하고,
        // // 조건문을 통해 isitOver99999와 olimsu를 할당하고, 99999이내가 되도록 num을 조정한다.
        // // printf("result : %d\n", index->num);
        long long int result = (long long)(index->num) * (long long)n;

        // test power
        // printf("result : num(%d) * n(%d) = result(%lld)\n", index->num, n, result);
        if (result > 99999)
        {
            index->isitOver99999 = 1;
            index->olimsu = result / 100000;
            index->num = result % 100000;
        }
        else
        {
            index->num = result;
        }
        index = index->frontDigit;
    }
}

// long long int multiple(struct partOfNum *index, int n)
// {
//     long long int result = (index->num) * n;
//     if (result > 99999)
//     {
//         index->isitOver99999 = 1;
//         index->olimsu = result / 100000;
//         index->num = result % 100000;
//     }
//     else
//     {
//         index->num = result;
//     }
//     return result;
// }
// void addOlimsu(struct partOfNum *index)
// {
//     // addOlimsu함수가 수행하는것 :
//     // 1. 이전 자릿수의 올림으로 인해 num이 99999가 넘었을 경우 조정한다.
//     // 2. isitOver99999가 참이면 index->frontdigit의 num에 올림수를 더하고,
//     // isitOver99999와 olimsu를 초기화한다.
//     if (index->num > 99999)
//     {
//         index->olimsu += index->num / 100000;
//         index->isitOver99999 = 1;
//         index->num /= 100000;
//     }
//     if (index->isitOver99999 == 1)
//     {
//         if (index->frontDigit == NULL)
//         {
//             // index가 head
//         }
//         else
//         {
//             index->frontDigit->num += index->olimsu;
//         }
//         index->isitOver99999 = 0;
//         index->olimsu = 0;
//     }
// }

void multipleSum(struct partOfNum **head, struct partOfNum **tail)
{
    // addOlimsu함수가 수행하는것 :
    // 1. 이전 자릿수의 올림으로 인해 num이 99999가 넘었을 경우 조정한다.
    // 2. isitOver99999가 참이면 index->frontdigit의 num에 올림수를 더하고,
    // isitOver99999와 olimsu를 초기화한다.
    struct partOfNum *index = *tail;
    while (index != NULL)
    {
        if (index->num > 99999)
        {
            // 1. 이전 자릿수의 올림으로 인해 num이 99999가 넘었을 경우 조정한다.
            index->olimsu += index->num / 100000;
            index->isitOver99999 = 1;
            index->num %= 100000;
        }
        if (index->isitOver99999 == 1)
        {
            if (index->frontDigit == NULL)
            {
                // index가 head
                NewPartOfNum(head, tail, index->olimsu);
            }
            else
            {
                index->frontDigit->num += index->olimsu;
            }

            index->isitOver99999 = 0;
            index->olimsu = 0;
        }
        index = index->frontDigit;
    }
}