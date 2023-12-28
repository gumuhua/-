#include <stdio.h>
#include <stdlib.h>
#define max 1000
int compare(const void *x,const void *y){
	return *(int *)x-*(int *)y;
}
int main (){
	int A[max],B[max];
	int len_A,len_B;
	scanf ("%d",&len_A);
	for (int i=0;i<len_A;i++){
		scanf ("%d",&A[i]);
	}
	scanf ("%d",&len_B);
	for (int j=len_A,i=0;i<len_B;i++,j++){
		scanf ("%d",&B[i]);
		A[j]=B[i];
	}
	qsort(A,len_A+len_B,sizeof(A[0]),compare);
	for (int i=0;i<len_A+len_B;i++){
		printf ("%d ",A[i]);
	}
	int mid=(len_A+len_B)/2;
	if ((len_A+len_B)%2==0){
		printf ("中位数：%.1lf",(A[mid]+A[mid-1])/2.0);
	}else{
		printf ("中位数：%.1lf",A[mid]);
	}
	return 0;
}
