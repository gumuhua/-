#include <stdio.h>
#define max 1000
void sift(int num[],int left,int right){
	int i=left,j=2*i;
	int t=num[i];
	while (j<=right){
		if (j<right&&num[j]>num[j+1]){
			j++;
		}
		if (t>num[j]){
			num[i]=num[j];
			i=j;
			j=2*i;
		}else{
			break;
		}
	}
	num[i]=t;
}
void sift_sort(int num[],int n){
	for (int i=n/2;i>=1;i--){
		sift(num,i,n);
	}
	for (int i=n;i>=2;i--){
		int temp=num[1];
		num[1]=num[i];
		num[i]=temp;
		sift(num,1,i-1);
	}
	printf ("小根堆排序后：");
	for (int i=1;i<=n;i++){
		printf ("%d ",num[i]);
	}
}
int main (){
	int n;
	int num[max];
	scanf ("%d",&n);
	for (int i=1;i<=n;i++){
		scanf ("%d",&num[i]);
	}
	sift_sort(num,n);
	return 0;
}

  