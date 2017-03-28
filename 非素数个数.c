#include <stdio.h>
#include <math.h>
int main() {
    int a,b;
    while (scanf("%d %d",&a,&b)!=EOF) {
        int count = 0;
        for (int i=a; i<=b; i++) {
            int flag = 1;
            int bound = (int)sqrt(i) + 1;
            for (int j=2; j<bound; j++) {
                if (i % j == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                count++;
            }
        }
        printf("%d\n",b-a+1-count);
    }
    return 0;
}
