#include <stdio.h>

int main()
{
    int ampere, w, v, result;
    scanf("%d", &ampere);
    scanf("%d %d", &w, &v);
    int adapterAmpere = w / v;
    if (adapterAmpere >= ampere)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    printf("%d", result);
    return 0;
}