#include <stdio.h>
#include <stdlib.h>

// n개의 보울이 있다. 보울 i는 mi개의 마블을 가지고 있다. 게임의 한 스텝은 보울에서 하나의 마블을 제거하는 것이다.
// 보울i에서 마블을 제거할 때, 보울1~i-1에 마블 하나가 추가된다. 만일 보울1에 마블이 제거될때, 아무 보울도 마블을 추가하지 않는다.
// 게임은 각 보울이 비어지고 나면 끝난다.

// 몇번의 스텝이 필요한지 구하라. 모든 보울은 충분히 크며, 따라서 모든 스텝은 수행될 수 있다.

// input : 여러개의 테스트라인을 포함하고 있다. 테스트라인의 첫번째 수는 n이고, 다음 줄은 시작할 때 보울에 들어있는 마블 수를 각각 나타낸다. 0이 나오면 마지막 테스트케이스 이다.
// output : 각 라인에, 이 게임을 끝내기 위해 몇번의 스텝이 필요한지 출력한다.
int main()
{
    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        unsigned long long sum = 0;
        unsigned int temp;
        unsigned long long twoSquare = 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            sum += temp * twoSquare;
            twoSquare *= 2;
        }
        printf("%llu\n", sum);
        scanf("%d", &n);
    }
    return 0;
}