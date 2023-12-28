#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 10
void Tong_sort(int *num, int n) {
    int Tong[10][max] = {0};
    int count[10] = {0};
    for (int i=1;i<=max;i++) {
        for (int j =0;j<n;j++){
            int key=(num[j]/(int)(pow(10,i-1)))% 10;
            Tong[key][count[key]]=num[j];
            count[key]++;
        }
        int t=0;
        for (int j=0;j<10;j++){
            for (int k=0;k<count[j];k++){
                num[t]=Tong[j][k];
                t++;
            }
            count[j]=0;
        }
    }
}

int main() {
    int num[max];
    int n;
    scanf ("%d",&n);
    for (int i=0;i<n;i++) {
        printf("%d",&num[i]);
    }
    Tong_sort(num,n);
    printf("基数排序后：");
    for (int i=0;i<n;i++){
        printf("%d ",num[i]);
    }
    printf("\n");

    return 0;
}
