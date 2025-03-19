#include <stdio.h>

/*
indirect indexing이 먼디
s와 t의 길이가 같은 문자열 쌍 (s,t)가 n개 있다.
s에서 글자 x가 등장하는 위치 p
s와 같은 쌍의 t의 p번째 글자(대문자로)
*/
/*
문제 : 길이가 얼마인지 모르는 문자열을 어떻게 저장하는가?
*/
int findX(char *);
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char s[1000000], t[1000000]; // 이것보다 더 나은 방법이 없나?
        scanf("%s %s", s, t);
        // printf("s : %s, t : %s\n", s, t);
        char pthChar = t[findX(s)]; // findX : s에서 x의 위치를 찾아 찾은 위치(인덱스)를 반환한다.
        if ((pthChar >= 97) && (pthChar <= 122))
        {
            pthChar = pthChar - 32;
        }
        printf("%c", pthChar);
    }
    return 0;
}

int findX(char *a)
{
    int index = 0;
    while (a[index] != '\0')
    {
        if ((a[index] == 'x') || (a[index] == 'X'))
        {
            return index;
        }
        else
        {
            index++;
        }
    }
    printf("\nx를 찾을 수 없습니다.\n");
    return 0;
}