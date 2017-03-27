#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double list[1001]={0};                                      //用来存放每人金额
int temp[1001]={0};                                         //存放随机数
int main() {
    double price;
    int num;                                                //红包金额，份数
    while (scanf("%lf %d",&price,&num)!=EOF) {
        if (price/num < 0.01) {
            printf("输入金额不够大家分，请重新输入：\n");
            continue;
        }
        double sum = 0;
        double last_sum = 0;
        srand((unsigned)time(NULL));
        for (int i=1; i<=num; i++) {
            temp[i] = rand()%100 + 1;                       //随机产生num个1-100的随机数
            sum += temp[i];
        }
        for (int i=1; i<num; i++) {
            list[i] = ((int)(temp[i]/sum*price*100))/100.0; //按比例计算每位金额保留两位小数
            if(list[i]<0.01) list[i] = 0.01;                //最少可获得0.01元
            last_sum += list[i];
        }
        list[num] = price - last_sum;                       //最后一位获得剩余金额
        for (int i=1; i<=num; i++) {
            if (i == 1) printf("%.2f",list[i]);
            else printf(" %.2f",list[i]);
        }
        printf("\n");
    }
    return 0;
}
