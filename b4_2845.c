#include <stdio.h>

int main()
{
    int peoperPerMeterSquare, partyArea;
    int paperNumber[5];
    scanf("%d %d", &peoperPerMeterSquare, &partyArea);
    int realPeople = peoperPerMeterSquare * partyArea;
    // scanf("%d %d %d %d %d", paperNumber);
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &paperNumber[i]);
        printf("%d ", paperNumber[i] - realPeople);
    }
    return 0;
}