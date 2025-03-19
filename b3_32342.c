#include <stdio.h>

/*
input
1. 소리의 개수 q
2. 소리(문자열) s

output
s마다 wow의 개수
*/

int isitWow(char scream[1000], int index);
int main()
{
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        char scream[1001];
        scanf("%s", scream);

        // 입력 확인
        // printf("%s\n", scream);
        // 입력 확인 끝
        int count = 0, index = 2;

        while (scream[index] != '\0')
        {
            count += isitWow(scream, index++);
        }
        printf("%d\n", count);
    }
}

int isitWow(char scream[1000], int index)
{
    // index-2, index-1, index가 각각 w,o,w인지 검사한다.
    if ((scream[index - 2] == 'W') || (scream[index - 2] == 'w'))
    {
        if ((scream[index - 1] == 'O') || (scream[index - 1] == 'o'))
        {
            if ((scream[index] == 'W') || (scream[index] == 'w'))
            {
                return 1;
            }
        }
    }
    return 0;
}