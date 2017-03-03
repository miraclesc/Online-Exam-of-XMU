/*
题目描述：
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
输入：
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
输出：
每组数据输出一行，即日期差值
样例输入：
20110412
20110422
样例输出：
11
*/

#include <stdio.h>
#include <stdlib.h>
int leap(int x){
    if((x%100!=0 && x%4==0) || x%400==0) return 1;
    else return 0;
}
int month_day[13][2] = {
0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31
};
int buf[5001][13][32];
int abs(int x){
    return x<0?-x:x;
}
int main() {
    int count = 0;
    int day=1;
    int month=1;
    int year=0;
    while(year!=5001){
        buf[year][month][day] = count;
        day++;
        if (day>month_day[month][leap(year)]) {
            day = 1;
            month++;
            if (month>12) {
                month = 1;
                year++;
            }
        }
        count++;
    }
    int day1,month1,year1;
    int day2,month2,year2;
    while (scanf("%4d%2d%2d",&year1,&month1,&day1)!=EOF) {
        scanf("%4d%2d%2d",&year2,&month2,&day2);
        printf("%d\n",abs(buf[year1][month1][day1]-buf[year2][month2][day2])+1);
    }
    return 0;
}
