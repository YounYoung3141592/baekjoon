#include <stdio.h>

/*
SP지역엔 연속해서 비가 온다. : meteorology?
rain diary : 매주 일요일에 비가 왔는지 아닌지 적는다.
모든 기록은 그 월의 며칠이였는지 적는다.
마지막 기록이 2주 전이고, 지난주 일요일의 기록을 하는것을 잊어버렸지만,
비가 온 것은 확실하다. 고로 오늘과 지난주 일요일의 기록을 둘 다 적기로 했다.

입력
n : 오늘 날짜
m : 2주 전 일요일의 날짜

출력
지난주 일요일의 날짜

오늘이 일요일이라는 말은 없는데??? 그럼 이번 달이 며칠이였는지 어떻게 알지?
today opened니까 오늘이 일요일인가?
*/
int main()
{
    int lastRecord, today, lastSunday;
    scanf("%d %d", &today, &lastRecord);
    if (today > lastRecord)
    {
        // 2주간 달이 바뀌지 않았다.
        lastSunday = (today + lastRecord) / 2;
    }
    else
    {
        // 2주간 달이 바뀌었다.
        // 지난주 일요일이 이번달이려면 today가 8이상이여야함
        if (today >= 8)
        {
            lastSunday = today - 7;
        }
        else
        {
            lastSunday = lastRecord + 7;
        }
    }
    printf("%d", lastSunday);
    return 0;
}