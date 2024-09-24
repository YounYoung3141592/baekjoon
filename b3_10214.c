#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int korea = 0, yonsei = 0;
        for (int j = 0; j < 9; j++)
        {
            int ktemp, ytemp;
            scanf("%d %d", &ytemp, &ktemp);
            yonsei += ytemp;
            korea += ktemp;
        }
        if (korea == yonsei)
        {
            printf("Draw\n");
        }
        else
        {
            printf("%s\n", (korea > yonsei) ? "Korea" : "Yonsei");
        }
    }
    return 0;
}
