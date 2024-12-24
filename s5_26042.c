#include <stdio.h>
#include <stdlib.h>

// 흐름
//     식당 줄서기 : 선입선출
// 입력
//     1 a : 번호가 a인 학생이 맨 뒤에 줄을 섰다.
//     2 : 식사 1인분이 준비되어 학생 한명이 식사를 시작한다.
// 출력
//     식당에 줄을 선 최대 학생수, 이때 맨 뒤에 선 학생의 번호

// linked list를 구현하자!

struct student
{
    int value;
    struct student *front;
    struct student *back;
};

void studentIn(int num, struct student **head, struct student **tail);
void studentOut(struct student **head, struct student **tail);
void showStack(struct student *head, int index);
int main()
{
    int lines, first, second, maxStudent = 0, index = 0, maxStudentNum;
    ;
    struct student *head = NULL, *tail = NULL;

    scanf("%d", &lines);
    for (int i = 0; i < lines; i++)
    {
        scanf("%d", &first);
        switch (first)
        {
        case 1:
            scanf("%d", &second);
            studentIn(second, &head, &tail);
            index++;
            if (index > maxStudent)
            {
                maxStudent = index;
                maxStudentNum = tail->value;
            }
            else if (index == maxStudent)
            {
                maxStudentNum = (tail->value < maxStudentNum) ? tail->value : maxStudentNum;
            }
            // test
            // showStack(head, index);
            break;

        case 2:
            studentOut(&head, &tail);
            index--;
            // test
            // showStack(head, index);
            break;
        }
    }
    // // test
    // studentIn(1, &head, &tail);
    // showStack(head);
    // studentIn(2, &head, &tail);
    // showStack(head);
    // studentOut(&head);
    // showStack(head);
    // return 0;

    printf("%d %d", maxStudent, maxStudentNum);
    return 0;
}

void studentIn(int num, struct student **head, struct student **tail)
{
    struct student *newStudent = (struct student *)malloc(sizeof(struct student));
    if (*head == NULL)
    {
        // 맨 처음 학생
        newStudent->front = NULL;
        newStudent->back = NULL;
        newStudent->value = num;

        *head = newStudent;
        *tail = newStudent;
    }
    else
    {
        // 맨 처음이 아닌 경우
        newStudent->front = *tail;
        newStudent->back = NULL;
        newStudent->value = num;

        (*tail)->back = newStudent;
        *tail = newStudent;
    }
    return;
}

void studentOut(struct student **head, struct student **tail)
{
    struct student *tempHead = *head;
    *head = (*head)->back;
    free(tempHead);
    return;
}

void showStack(struct student *head, int index)
{
    printf("index : %d\n", index);
    if (head != NULL)
    {
        struct student *tempHead = head;

        while (tempHead != NULL)
        {
            printf("student num : %d\n", tempHead->value);
            tempHead = tempHead->back;
        }
        printf("\n");
    }
    else
    {
        printf("head가 null입니다.\n");
    }
    return;
}