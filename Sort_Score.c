/*题目描述：
    有N个学生的数据，将学生数据按成绩高低排序，如果成绩相同则按姓名字符的字母序排序，如果姓名的字母序也相同则按照学生的年龄排序，并输出N个学生排序后的信息。
输入：
    测试数据有多组，每组输入第一行有一个整数N（N<=1000），接下来的N行包括N个学生的数据。
    每个学生的数据包括姓名（长度不超过100的字符串）、年龄（整形数）、成绩（小于等于100的正数）。
输出：
    将学生信息按成绩进行排序，成绩相同的则按姓名的字母序进行排序。
    然后输出学生信息，按照如下格式：
    姓名 年龄 成绩
样例输入：
3
abc 20 99
bcd 19 97
bed 20 97
样例输出：
bcd 19 97
bed 20 97
abc 20 99
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    char name[101];
    int age;
    int score;
}buf[1000];
int main() {
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++) {
            scanf("%s %d %d",buf[i].name,&buf[i].age,&buf[i].score);
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n-1-i; j++) {
                if (buf[j].score>buf[j+1].score) {
                    struct student temp = buf[j];
                    buf[j] = buf[j+1];
                    buf[j+1] = temp;
                }else if(buf[j].score==buf[j+1].score){
                    if (strcmp(buf[j].name, buf[j+1].name)>0) {
                        struct student temp = buf[j];
                        buf[j] = buf[j+1];
                        buf[j+1] = temp;
                    }else if(strcmp(buf[j].name, buf[j+1].name)==0){
                        if (buf[j].age>buf[j+1].age) {
                            struct student temp = buf[j];
                            buf[j] = buf[j+1];
                            buf[j+1] = temp;
                        }
                    }
                }
            }
        }
        for (int i=0; i<n; i++) {
            printf("%s %d %d\n",buf[i].name,buf[i].age,buf[i].score);
        }
    }
    return 0;
}
