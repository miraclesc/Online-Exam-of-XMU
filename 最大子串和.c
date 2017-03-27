#include <stdio.h>
int list[101];
struct sub{
    int begin;
    int end;
    int sum[100];
    int add;                                            //子串和的开始，结束，每一位的和，最大和
}buf[101];
int main() {
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++) {
            scanf("%d",&list[i]);
        }
        for (int i=0; i<n; i++) {                       //求出以第i开始的最大子串和
            int max = 0;
            int t;
            buf[i].begin = i;
            buf[i].sum[i] = list[i];
            t =list[i];
            for (int j=i+1; j<n; j++) {
                t += list[j];;
                buf[i].sum[j] = t;
            }
            for (int j=i; j<n; j++) {                   //找到以第i个开始的最大和
                if (max <= buf[i].sum[j]) {
                    max = buf[i].sum[j];
                    buf[i].add = max;
                    buf[i].end = j;
                }
            }
        }
        int temp = 0;
        int start = 0;
        int last = 0;
        for (int i=0; i<n; i++) {                       //找到所有子串的最大和
            if (buf[i].add > temp) {
                temp = buf[i].add;
                start = buf[i].begin;
                last = buf[i].end;
            }
        }
        for (int i=start; i<=last; i++) {
            printf("%d ",list[i]);
        }
        printf("\n%d\n",temp);
    }
    return 0;
}
