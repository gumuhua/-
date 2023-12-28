#include <stdio.h>
#define max 100
void shellsort(int a[],int n){
	int gap,t;
	gap=n/2;
	while (gap>0){
		for (int i=gap;i<n;i++){
			t=a[i];
			int j=i-gap;
			while (j>=0&&t<a[j]){
				a[j+gap]=a[j];
				j-=gap;
			}
			a[j+gap]=t;
		}
		gap/=2;
	}
}
int main (){
	int n;
	int a[max];
	scanf ("%d",&n);
	for (int i=0;i<n;i++){
		scanf ("%d",&a[i]);
	}
	shellsort(a,n);
	printf ("排序后：");
	for (int i=0;i<n;i++){
		printf ("%d ",a[i]);
	}
}
/*10
6 12 458 5 4 28 19 1230 9 47*/