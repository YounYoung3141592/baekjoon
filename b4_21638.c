#include <stdio.h>

int main()
{
    // 태풍 조건 : 영하, 풍속 10/s이상
    // cold snap : 내일이 더 추움
    // strong wind : 풍속이 더 높음
    int temperature[2], windSpeed[2];
    scanf("%d %d", &temperature[0], &windSpeed[0]);
    scanf("%d %d", &temperature[1], &windSpeed[1]);
    if ((temperature[1] < 0) && (windSpeed[1] > 9))
    {
        printf("A storm warning for tomorrow! Be careful and stay home if possible!\n");
        return 0;
    }
    else if (temperature[1] < temperature[0])
    {
        printf("MCHS warns! Low temperature is expected tomorrow.\n");
        return 0;
    }
    else if (windSpeed[1] > windSpeed[0])
    {
        printf("MCHS warns! Strong wind is expected tomorrow.\n");
        return 0;
    }
    printf("No message\n");
    return 0;
}