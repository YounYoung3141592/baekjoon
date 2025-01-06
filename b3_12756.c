#include <stdio.h>

int main()
{
    int Aplayer[2], Bplayer[2];
    scanf("%d %d", &Aplayer[0], &Aplayer[1]);
    scanf("%d %d", &Bplayer[0], &Bplayer[1]);
    // if ((Aplayer[1] / Bplayer[0]) == (Bplayer[1] / Aplayer[0]))
    // {
    //     printf("DRAW");
    // }
    // else if ((Aplayer[1] / Bplayer[0]) < (Bplayer[1] / Aplayer[0]))
    // {
    //     printf("PLAYER B");
    // }
    // else
    // {
    //     printf("PLAYER A");
    // }

    // 정석으로
    while ((Aplayer[1] > 0) && (Bplayer[1] > 0))
    {
        Aplayer[1] -= Bplayer[0];
        Bplayer[1] -= Aplayer[0];
    }
    if ((Aplayer[1] <= 0) && (Bplayer[1] <= 0))
    {
        printf("DRAW");
    }
    else if ((Aplayer[1] <= 0) && (Bplayer[1] > 0))
    {
        printf("PLAYER B");
    }
    else
    {
        printf("PLAYER A");
    }
    return 0;
}
