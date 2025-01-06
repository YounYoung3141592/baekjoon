#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

/*
무한의 중심 s에 외접하는, 지름이r인 원.
원의 맨 왼쪽에 s를 접하는 지름이 r인 원 c1
원의 맨 오른쪽에 s를 접하는 지름이 r*a인 원 c2
원의 맨 왼쪽에 s를 접하는 지름이 r*a/b인 원 c3
c2*a, c3*a/b를 지속적으로 생성
지름이 0이 될때까지 구하기
위 원의 모든 넓이의 합을 구하기
*/
double getAllArea(int, int, int);
int main()
{
    int lines;
    scanf("%d", &lines);
    for (int i = 0; i < lines; i++)
    {
        int r, a, b;
        scanf("%d %d %d", &r, &a, &b);
        printf("Case #%d: %.6lf\n", i + 1, getAllArea(r, a, b));
    }
    return 0;
}

double getAllArea(int r, int a, int b)
{
    double result = 0;
    while (r >= 1)
    {
        result += pow(r, 2) * (pow(a, 2) + 1);
        r = r * a / b;
    }
    return result * M_PI;
}