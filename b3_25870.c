#include <stdio.h>
/*
문자열의 모든 문자가 짝수번 등장하면 그 문자열을 even하다고 한다.
문자열의 모든 문자가 홀수번 등장하면 그 문자열을 odd하다고 한다.

주어진 문자열이 even인지, odd인지, 둘 중 아무도 아닌지 판별하여러

출력
0 : even
1 : odd
2 : neither
*/
int isitEven(int *);
int isitOdd(int *);
int main()
{
    char string[100];
    scanf("%s", string);
    int alphabet[26];
    for (int i = 0; i < 26; i++)
    {
        alphabet[i] = 0;
    }
    int index = 0;
    while (string[index] != '\0')
    {
        alphabet[string[index++] - 'a']++;
        // printf("%c : %d\n", string[index - 1], alphabet[string[index - 1] - 'a']);
    }

    // alphabet test
    // for (int i = 0; i < 26; i++)
    // {
    //     printf("%d ", alphabet[i]);
    // }
    if (isitEven(alphabet))
    {
        printf("0");
    }
    else if (isitOdd(alphabet))
    {
        printf("1");
    }
    else
    {
        printf("2");
    }
}

int isitEven(int *alphabet)
{
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] % 2 == 1)
        {
            return 0;
        }
    }
    return 1;
}

int isitOdd(int *alphabet)
{
    for (int i = 0; i < 26; i++)
    {
        if ((alphabet[i] % 2 == 0) && (alphabet[i] != 0))
        {
            return 0;
        }
    }
    return 1;
}