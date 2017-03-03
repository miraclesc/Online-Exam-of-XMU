/*
题目描述：
给出年分m和一年中的第n天，算出第n天是几月几号。
输入：
输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。
输出：
可能有多组测试数据，对于每组数据，
按 yyyy-mm-dd的格式将输入中对应的日期打印出来。
样例输入：
2000 3
2000 31
2000 40
2000 60
2000 61
2001 60
样例输出：
2000-01-03
2000-01-31
2000-02-09
2000-02-29
2000-03-01
2001-03-01
*/

#include <stdio.h>
#include <stdlib.h>
int leap(int x){
    if((x%100!=0 && x%4==0) || x%400==0) return 1;
    else return 0;
}
int month_day[12][2] = {
    31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31
};
int main() {
    int year;
    int num;
    while (scanf("%d %d",&year,&num)!=EOF) {
        int m = 0;
        int month = 0;
        int pre_month_add=0;
        int day =0;
        while (num>m) {
            m += month_day[month][leap(year)];
            month++;
        }
        for (int i=0; i<month-1; i++) {
            pre_month_add += month_day[i][leap(year)];
        }
        day = num - pre_month_add;
        printf("%04d-%02d-%02d\n",year,month,day);
    }
    return 0;
}
