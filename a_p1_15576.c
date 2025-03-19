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
void applyOlimsu(struct partOfNum **, struct partOfNum *);
void printForDebug(struct partOfNum *, int);
void findHeadTailByFigure(struct partOfNum *, struct partOfNum *, struct partOfNum **, struct partOfNum **, int);
int main()
{
    char a[300000], b[300000];
    scanf("%s %s", a, b);
    struct partOfNum *a_head = makeNum(a);
    struct partOfNum *b_head = makeNum(b);
    multiple(a_head, b_head);

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

    while (index >= 4)
    {
        struct partOfNum *partofnum = (struct partOfNum *)malloc(sizeof(struct partOfNum));
        int temp = 0;
        for (int i = 0; i < 5; i++)
        {
            temp += ((int)origin[index - i] - 48) * pow(10, i); // 이거 맞나? 갑자기 헷갈리네
        }
        partofnum->value = temp;
        partofnum->lowerFigure = NULL;
        partofnum->upperFigure = NULL;
        partofnum->olimsu = 0;
        partofnum->figure = ((maxIndex - index) / 5) * 5;
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
        partofnum->figure = ((maxIndex - index) / 5) * 5;
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
    // printf("\nnow index is null.\n");
    printf("\n");
}

void multiple(struct partOfNum *a_head, struct partOfNum *b_head)
{
    // 어제 정리해놓은 로직을 바탕으로 다시 한번 짜보기
    int maxFigure = a_head->figure + b_head->figure;
    struct partOfNum *resultHead = NULL, *resultTail = NULL;
    for (int f = maxFigure; f >= 0; f -= 5)
    {
        struct partOfNum *tempAhead = NULL, *tempBtail = NULL;
        findHeadTailByFigure(a_head, b_head, &tempAhead, &tempBtail, f);
        long long int multiSum = 0;
        while ((tempAhead != NULL) && (tempBtail != NULL))
        {
            long long aValue = tempAhead->value, bValue = tempBtail->value;
            multiSum += aValue * bValue;
            tempAhead = tempAhead->lowerFigure;
            tempBtail = tempBtail->upperFigure;
        }

        // multiSum을 바탕으로 pon만들기
        struct partOfNum *newPon = (struct partOfNum *)malloc(sizeof(struct partOfNum));
        newPon->figure = f;
        newPon->olimsu = multiSum / 100000;
        newPon->value = multiSum % 100000;
        newPon->lowerFigure = NULL;
        if (resultHead == NULL)
        {
            // 맨 처음 pon
            newPon->upperFigure = NULL;
            resultHead = newPon;
            resultTail = newPon;
        }
        else
        {
            // 이전 pon이 존재함.
            resultTail->lowerFigure = newPon;
            newPon->upperFigure = resultTail;
            resultTail = newPon;
        }
        multiSum = 0;
    }
    applyOlimsu(&resultHead, resultTail);
    printPartOfNum(resultHead);
}

void applyOlimsu(struct partOfNum **head, struct partOfNum *tail)
{
    struct partOfNum *index = tail;
    while (index != NULL)
    {
        // 아래 자릿수의 올림수로 인해 올림수가 생겼을 가능성 대비
        int tempValue = index->value;
        index->olimsu += tempValue / 100000;
        index->value = tempValue % 100000;
        if (index->olimsu > 0)
        {
            // 올림수가 존재하는 경우
            if (index->upperFigure == NULL)
            {
                // index가 head인데 올림수가 존재함
                struct partOfNum *pon = (struct partOfNum *)malloc(sizeof(struct partOfNum));
                pon->figure = (*head)->figure + 5;
                pon->lowerFigure = (*head);
                pon->olimsu = index->olimsu / 100000;
                pon->upperFigure = NULL;
                pon->value = index->olimsu % 100000;
                *head = pon;
            }
            else
            {
                // index가 head는 아닌데 올림수가 존재함
                index->upperFigure->value += index->olimsu;
                index->olimsu = 0;
            }
        }
        index = index->upperFigure;
    }
}

void printForDebug(struct partOfNum *head, int option)

{
    if (head == NULL)
    {
        printf("head가 널입니다.\n");
        return;
    }
    switch (option)
    {
    case 0: // head아래 전체 pon을 출력한다.
        struct partOfNum *index = head;
        while (index != NULL)
        {
            printf("figure : %d | value : %d | olimsu : %d\n", index->figure, index->value, index->olimsu);
            if (index->upperFigure != NULL)
            {
                printf("upperFigure's value : %d", index->upperFigure->value);
            }
            else
            {
                printf("upperFigure : null");
            }
            if (index->lowerFigure != NULL)
            {
                printf("| lowerFigure's value : %d", index->lowerFigure->value);
            }
            else
            {
                printf("| lowerFigure : null");
            }
            printf("\n\n");
            index = index->lowerFigure;
        }
        break;
    case 1: // 주어진 head의 값만 출력한다.
        printf("figure : %d | value : %d | olimsu : %d\n", head->figure, head->value, head->olimsu);
        if (head->upperFigure != NULL)
        {
            printf("upperFigure's value : %d", head->upperFigure->value);
        }
        else
        {
            printf("upperFigure : null");
        }
        if (head->lowerFigure != NULL)
        {
            printf("| lowerFigure's value : %d", head->lowerFigure->value);
        }
        else
        {
            printf("| lowerFigure : null");
        }
        printf("\n\n");
    default:
        break;
    }

    return;
}

void findHeadTailByFigure(struct partOfNum *a_head, struct partOfNum *b_head, struct partOfNum **tempAhead, struct partOfNum **tempBtail, int figure)
{
    struct partOfNum *temptempAhead = a_head, *temptempBtail = b_head;
    int minBfigure;
    while (temptempAhead != NULL)
    {
        if (temptempAhead->figure == figure)
        {
            *tempAhead = temptempAhead;
            minBfigure = figure - temptempAhead->figure;
            break;
        }
        else if (figure > temptempAhead->figure)
        {
            *tempAhead = temptempAhead;
            minBfigure = figure - temptempAhead->figure;
            break;
        }
        else
        {
            temptempAhead = temptempAhead->lowerFigure;
        }
    }
    while ((temptempBtail->figure != minBfigure) && (temptempBtail != NULL))
    {
        temptempBtail = temptempBtail->lowerFigure;
    }
    *tempBtail = temptempBtail;
    return;
}