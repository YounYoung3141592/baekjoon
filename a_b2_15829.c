#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int l;
    unsigned long long int sum = 0;
    scanf("%d", &l);
    char *string = (char *)malloc(sizeof(char) * l);
    int r = 31, m = 1234567891;
    scanf("%s", string);
    for (int i = 0; i < l; i++)
    {
        long long int temp = ((int)pow(r, i) % m) * (string[i] - 96) % m;
        sum += temp;
        sum %= m;
    }
    printf("%lld\n", sum);
    return 0;
}
