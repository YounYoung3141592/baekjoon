#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
수의 길이는 300000자리를 넘지 않는다.
곱하면? (300000)^2자리?
자료형을 만들자...

*/
struct partOfNum
{
    int value;
    int figure; // figure은 0,5,10 등 5의 배수(value의 가장 작은 자리수)로 하기기
    struct partOfNum *upperFigure;
    struct partOfNum *lowerFigure;
    int olimsu;
};
struct partOfNum *makeNum(char *);
void printPartOfNum(struct partOfNum *);
void multiple(struct partOfNum *, struct partOfNum *);
void applyOlimsu(struct partOfNum **);
int main()
{
    char a[300000], b[300000];
    scanf("%s %s", a, b);
    // ab가 문자열에 잘 들어간 것 확인함
    // printf("a : %s\nb : %s\n", a, b);
    struct partOfNum *a_head = makeNum(a);
    struct partOfNum *b_head = makeNum(b);
    printPartOfNum(a_head);
    printPartOfNum(b_head);
    // multiple(a, b);
    return 0;
}

struct partOfNum *makeNum(char *origin)
{
    // 이 과정을 python의 a[-1]처럼 처리할 수 있는 방법이 있나?
    int maxIndex = 0;
    while (origin[maxIndex] != '\0')
    {
        maxIndex++;
    }

    int index = maxIndex - 1, i = 0;
    // printf("maxindex : %d\n", maxIndex);
    struct partOfNum *head = NULL;
    // while ((index >= 0) && (i < 5))
    // {
    //     struct partOfNum *partofnum = (struct partOfNum *)malloc(sizeof(struct partOfNum));
    //     if(head==NULL){
    //         //맨 처음 만듦
    //     }
    //     i++;
    // }

    // 정확히 어딜 잘못한 건지 모르겠어서 다시 짜보기로 함.
    //  while (index >= 0)
    //  {
    //      struct partOfNum *partofnum = (struct partOfNum *)malloc(sizeof(struct partOfNum));
    //      if (index >= 4)
    //      { // 저장할 수가 5개인가?
    //          int temp = (int)origin[index] + (int)origin[index - 1] * 10 + (int)origin[index - 2] * 100 + (int)origin[index - 3] * 1000 + (int)origin[index - 4] * 10000;
    //          printf("temp : %d\n", temp);
    //          partofnum->value = temp;
    //          partofnum->lowerFigure = NULL;
    //          partofnum->upperFigure = NULL;
    //          partofnum->olimsu = 0;
    //          index -= 5;
    //      }
    //      else
    //      { // 저장할 수가 5개 미만임
    //          int temp = 0;
    //          for (int i = 0; i <= index; i++)
    //          {
    //              temp += (int)origin[index - i] * pow(10, i); // 이거 맞나? 갑자기 헷갈리네
    //              printf("temp : %d\n", temp);
    //          }
    //          partofnum->value = temp;
    //          partofnum->lowerFigure = NULL;
    //          partofnum->upperFigure = NULL;
    //          partofnum->olimsu = 0;
    //          index = -1; // while문 종료료
    //      }
    //      if (head == NULL)
    //      { // 이게 첫 생성된 pon이다.
    //          head = partofnum;
    //      }
    //      else
    //      { // 이미 다른 head(pon)이 존재한다.
    //          head->upperFigure = partofnum;
    //          partofnum->lowerFigure = head;
    //          head = partofnum;
    //      }
    //  }

    while (index >= 4)
    {
        struct partOfNum *partofnum = (struct partOfNum *)malloc(sizeof(struct partOfNum));
        int temp = 0;
        for (int i = 0; i < 5; i++)
        {
            temp += ((int)origin[index - i] - 48) * pow(10, i); // 이거 맞나? 갑자기 헷갈리네
            // printf("originNum : %d, index : %d, temp : %d\n", (int)origin[index - i], index - i, temp);
        }
        // printf("temp : %d\n", temp);
        partofnum->value = temp;
        partofnum->lowerFigure = NULL;
        partofnum->upperFigure = NULL;
        partofnum->olimsu = 0;
        partofnum->figure = ((maxIndex - index) / 5) * 5;
        printf("temp : %d,figure : %d\n", partofnum->value, partofnum->figure);
        index -= 5;
        if (head == NULL)
        { // 이게 첫 생성된 pon이다.
            head = partofnum;
        }
        else
        { // 이미 다른 head(pon)이 존재한다.
            head->upperFigure = partofnum;
            partofnum->lowerFigure = head;
            head = partofnum;
        }
    }
    if ((0 <= index) && (index <= 3))
    { // 위 while문으로 다 나가고, 최종 head에 저장해야 할 자릿수가 1~4
        struct partOfNum *partofnum = (struct partOfNum *)malloc(sizeof(struct partOfNum));
        int temp = 0;
        for (int i = 0; i <= index; i++)
        {
            temp += ((int)origin[index - i] - 48) * pow(10, i); // 이거 맞나? 갑자기 헷갈리네
            // printf("originNum : %d, index : %d, temp : %d\n", (int)origin[index - i], index - i, temp);
        }
        partofnum->value = temp;
        partofnum->lowerFigure = NULL;
        partofnum->upperFigure = NULL;
        partofnum->olimsu = 0;
        index -= 5;
        if (head == NULL)
        { // 이게 첫 생성된 pon이다.
            head = partofnum;
        }
        else
        { // 이미 다른 head(pon)이 존재한다.
            head->upperFigure = partofnum;
            partofnum->lowerFigure = head;
            head = partofnum;
        }
    }
    // printf("makeNum end\n");
    return head;
}

void printPartOfNum(struct partOfNum *head)
{
    struct partOfNum *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->value);
        temp = temp->lowerFigure;
    }
    // printf("now index is null.\n");
    printf("\n");
}

void multiple(struct partOfNum *a_head, struct partOfNum *b_head)
{
    int maxFigure = a_head->figure + b_head->figure;
    // maxfigure계산, head 할당

    for (int figure = maxFigure; figure >= 0; figure -= 5)
    {
        // figure={x | a_maxFigure+b_maxFigure-5n(단, n은 (0<=n<=( a_maxFigure+b_maxFigure)/5범위의 정수)}
        if (figure <= a_head->figure)
        {
            //
        }
    }
}