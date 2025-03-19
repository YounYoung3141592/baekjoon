#include <stdio.h>
#include <stdlib.h>

/*
info
- 알파벳 묶음 =한 문자열이 최소로 가지는, 동일한 알파벳으로만 이루어진 문자열
- 쿼리
    - 1 a b : Sa ~ Sb에서 알파벳 묶음의 개수를 출력한다.
    - 2 a b : Sa ~ Sb의 모든 알파벳을 다음 순서 알파벳(z -> a)으로 변경한다.
input
1. 문자열 길이 n, 쿼리 개수 q
2. q개의 줄의 쿼리

output
1번 쿼리의 결과값을 한 줄에 하나씩 출력한다.
*/

void executeQuery(int query, char *string, int start, int end);
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    char *string = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", string);
    for (int i = 0; i < q; i++)
    {
        int query, start, end;
        scanf("%d %d %d", &query, &start, &end);
        executeQuery(query, string, start - 1, end - 1);
        // a번째 알파벳은 a-1인덱스에 존재하기 때문에, 싱크를 맞춘다.
    }
    return 0;
}

void executeQuery(int query, char *string, int start, int end)
{
    switch (query)
    {
    case 1:
        // start~end 인덱스의 알파벳묶음의 개수를 구하라.
        int count = 1;
        for (int i = start; i < end; i++)
        {
            if (string[i] != string[i + 1])
            {
                count++;
            }
        }
        printf("%d\n", count);
        break;

    case 2:
        // start~end 인덱스의 알파벳 순서를 +1 하라.
        for (int i = start; i <= end; i++)
        {
            if (string[i] == 'Z')
            {
                string[i] = 'A';
            }
            else
            {
                string[i] = string[i] + 1;
            }
        }
        break;
    }
}