#include <stdio.h>

int main(int argc, char const *argv[])
{
    int dwarf[9], sum = -100;
    int fakeDwarfIndex[2];
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &dwarf[i]);
        sum += dwarf[i];
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (dwarf[i] + dwarf[j] == sum)
            {
                fakeDwarfIndex[0] = i;
                fakeDwarfIndex[1] = j;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if ((i != fakeDwarfIndex[0]) && (i != fakeDwarfIndex[1]))
        {
            printf("%d\n", dwarf[i]);
        }
    }
    return 0;
}
