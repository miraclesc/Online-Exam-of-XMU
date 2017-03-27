#include <stdio.h>
int max (int a,int b) {
    return a > b ? a : b;
}
struct E{
    int w;                                  //花费
    int v;                                  //价值
}list[101];
int dp[1001];                               //记录状态数组，dp[i]表示总体积不大于i的最大价值之和
int main() {
    int s,n;                                //s最大容量，n物品总类
    while (scanf("%d %d",&s,&n)!=EOF) {
        for (int i=1; i<=n; i++) {
            scanf("%d %d",&list[i].w,&list[i].v);
        }
        for (int i=0; i<=s; i++) {
            dp[i] = 0;
        }
        for (int i=1; i<=n; i++) {
            for (int j=s; j>=list[i].w; j--) {
                dp[j] = max(dp[j-list[i].w]+list[i].v, dp[j]);
            }
        }
        printf("%d\n",dp[s]);
    }
    return 0;
}
