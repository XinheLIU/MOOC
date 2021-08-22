//编程题＃4：Tomorrow never knows？

//描述甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，如果告诉你a day in the life,真的会是tomorrow never knows?相信学了计概之后这个不会是难题，现在就来实现吧。
//读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。

//输入 输入仅一行，格式为yyyy-mm-dd的日期。

//输出 输出也仅一行，格式为yyyy-mm-dd的日期

#include <iostream>
#include <cstdio>
using namespace std;


int main(){
    int year, month, day;
    int dayTable[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
    int isLeapYear, daysOfMonth;
    scanf("%d-%d-%d", &year, &month, &day);
    isLeapYear = (year % 4 == 0 && year % 100 != 0)|| (year %400 == 0);
    daysOfMonth = dayTable[isLeapYear][month];
    ++day;
    if(day > daysOfMonth) {
        day = 1;
        ++month;
    }
    if(month > 12) {
        month = 1;
        ++year;
    }
    printf("%d-%02d-%02d\n", year, month, day);
    return 0;
}