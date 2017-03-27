#include <stdio.h>
int main() {
    int n;
    while (scanf("%d",&n)!=EOF) {
        int target = 0;
        int temp = n;
        while(temp > 0){
            target = target*10 + temp%10;
            temp /= 10;
        }
        if (target == n) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
