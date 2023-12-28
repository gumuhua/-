#include <stdio.h>
#define max 1000
void bubble_sort(int num[],int n){
	int number=0;
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n-1-i;j++){
			if (num[j]>num[j+1]){
				int t=num[j];
				num[j]=num[j+1];
				num[j+1]=t;
				number++;
			}else{
				continue;
			}
		}
	}
	printf ("最少变换步数是：%d",number);
}
int main (){
	int n;
	int num[max];
	scanf ("%d",&n);
	for (int i=0;i<n;i++){
		scanf ("%d",&num[i]);
	}
	bubble_sort(num,n);
	return 0;
}