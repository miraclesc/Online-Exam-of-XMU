#include <stdio.h>
int partition(int arr[],int low,int high){
    int key = arr[low];
    while (low<high) {
        while (low<high && arr[high]>=key) high--;
        if (low<high) arr[low++]=arr[high];
        while (low<high && arr[low]<=key) low++;
        if (low<high) arr[high--]=arr[low];
    }
    arr[low] = key;
    return low;
}
void Qsort(int arr[],int low,int high ){
    if (low < high) {
        int pos = partition(arr, low, high);
        Qsort(arr, low, pos-1);
        Qsort(arr, pos+1, high);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    int buf[100];
    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++) {
            scanf("%d",&buf[i]);
        }
        Qsort(buf, 0, n-1);
        for (int i=0; i<n; i++) {
            printf("%d ",buf[i]);
        }
        printf("\n");
    }
    return 0;
}
