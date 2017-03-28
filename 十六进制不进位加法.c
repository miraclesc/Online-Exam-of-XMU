#include <stdio.h>
#include <string.h>
int str_to_num(char x){                                     //将字符转化为数字
    int y;
    if (x >= '0' && x <= '9'){
        y = x - '0';
    } else if (x >= 'a' && x <= 'f') {
        y = x - 'a' + 10;
    } else y = x - 'A' + 10;
    return y;
}
char num_to_str(int x){                                     //将数字转化为字符
    char y;
    if (x >= 0 && x <= 9){
        y = x + '0';
    } else y = x - 10 + 'A';
    return y;
}
int main() {
    char a[10];
    char b[10];
    while (scanf("%s %s",a,b)!=EOF) {
        int lena = strlen(a);
        int lenb = strlen(b);
        char c[10];
        int index = 0;
        int x,y,z;
        for (int i=lena-1,j=lenb-1; i>=0||j>=0; i--,j--) {          //从字符串的最低位开始遍历
            if (i >= 0) {
                x = str_to_num(a[i]);
            }else x = 0;
            if (j >= 0) {
                y = str_to_num(b[j]);
            }else y = 0;
            z = (x+y)%16;                                           //十六进制不进位加法
            c[index++] = num_to_str(z);
        }
        for (int k=index-1; k>=0; k--) {
            if (k==index-1 && c[k]==0) continue;                    //首位不为0
            if (c[k] <= '9') {
                printf("%d\n",c[k]);
            }else printf("%c\n",c[k]);
        }
    }
    return 0;
}
