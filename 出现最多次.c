#include <stdio.h>
int list[101];
int temp[101];
int main() {
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++) {
            scanf("%d",&list[i]);
            temp[i] = 1;                        //每个数字出现过就至少出现过一次
        }
        for (int i=0; i<n; i++) {
            for (int j=i-1; j>=0; j--) {        //向前遍历，如果找到相同数字，则该位置的次数等于上个位置加1
                if(list[i] == list[j]){
                    temp[i] = temp[j] + 1;
                    break;
                }
            }
        }
        int max = 0;                            //标记最大次数
        int target = list[0];                   //出现最多次的数字
        for (int i=0; i<n; i++) {
            if (temp[i] > max) {
                max = temp[i];
                target = list[i];
            }
        }
        printf("%d\n",target);
    }
    return 0;
}
