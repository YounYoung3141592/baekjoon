#include <stdio.h>

void printDistance(char a[20], char b[20]);
int getLength(char w[20]);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char w1[20], w2[20];
        scanf("%s %s", w1, w2);
        printDistance(w1, w2);
    }
    return 0;
}

void printDistance(char w1[20], char w2[20])
{
    int length = getLength(w1);
    printf("Distances:");
    for (int i = 0; i < length; i++)
    {
        int distance = w1[i] - w2[i];
        // printf("%c %c : %d\n", w1[i], w2[i], distance);
        printf(" %d", (distance > 0) ? 26 - distance : distance * -1);
    }
    printf("\n");
    return;
}

int getLength(char w[20])
{
    int length = 0;
    while (w[length] != '\0')
    {
        length++;
    }
    return length;
}