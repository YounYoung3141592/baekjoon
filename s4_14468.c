#include <stdio.h>

struct cow
{
    char cowName;
    int start;
    int end;
};
int main()
{
    struct cow cows[26];
    char input[52];
    scanf("%s", input);

    for (int i = 0; i < 26; i++)
    {
        // cows초기 세팅
        cows[i].cowName = (char)(i + 65);
        cows[i].start = -1;
        cows[i].end = -1;
    }
    for (int i = 0; i < 52; i++)
    {
        int index = input[i] - 65;
        if (cows[index].start == -1)
        {
            // 처음
            cows[index].start = i;
        }
        else
        {
            cows[index].end = i;
        }
    }
    // test cows
    // for (int i = 0; i < 26; i++)
    // {
    //     printf("cowName : %c, start : %d, end : %d\n", cows[i].cowName, cows[i].start, cows[i].end);
    // }
    int meetSum = 0;
    for (int i = 0; i < 26; i++)
    {
        // 어떤 소 쌍 사이의 알파벳이 start라면, end가 이 소 쌍의 end보다 큰지 검사.
        // 크면 meetsum++;

        // test
        // printf("\ncow i : %c, cow i start : %d, cow i end : %d\n", cows[i].cowName, cows[i].start, cows[i].end);
        for (int j = cows[i].start + 1; j < cows[i].end; j++)
        {
            // test

            // printf("j : %d, cow j : %c, cow j start : %d, cow j end : %d\n", j, cows[input[j] - 65].cowName, cows[input[j] - 65].start, cows[input[j] - 65].end);
            if ((cows[input[j] - 65].start == j) && (cows[input[j] - 65].end > cows[i].end))
            {

                // j가 소의 start인 경우
                meetSum++;
            }
        }
    }
    printf("%d", meetSum);
    return 0;
}