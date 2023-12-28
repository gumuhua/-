#include <stdio.h>
#define max 100
void quicksort(int a[],int left,int right){
	int i,j;
	j=right;
	i=left;
	if (i>=j){
		return;
	}
	int temp=a[left];  //左边为基数，（右边先动）则左边后动，保证相遇时的值小于基数temp
	while (i<j){
		while (a[j]>=temp&&i<j){
			j--;
		}
		while(a[i]<=temp&&i<j){
			i++;
		}

		if (i<j){
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
		int t=a[left];
		a[left]=a[i];
		a[i]=t;
		quicksort(a,left,i-1);
		quicksort(a,i+1,right);
}
int main (){
	int n;
	int m=0;
	int a[max];
	scanf ("%d",&n);
	for (int i=0;i<n;i++){
		scanf ("%d",&a[i]);
	}
	quicksort(a,m,n-1);
	printf ("快速排序后：");
	for (int i=0;i<n;i++){
		printf ("%d ",a[i]);
	}
	return 0;
}
/*10
6 12 458 5 4 28 19 1230 9 47*/