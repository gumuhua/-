#include <stdio.h>
#include <string.h>
#define max 1000
void merge_sort(int x[],int len_x,int y[],int len_y){
	int i=0,j=0;
	int answer[max],k=0;
	while (i<len_x&&j<len_y){
		if (x[i]<y[j]){
			answer[k++]=x[i++];
		}else if (x[i]>y[j]){
			answer[k++]=y[j++];
		}else{
			answer[k++]=x[i++];
			answer[k++]=y[j++];
		}
	}
	if (i>=len_x){
		memcpy(answer+k,y+j,sizeof(y[0]));
	}
	if (j>=len_y){
		memcpy(answer+k,x+i,sizeof(x)[0]);
	}
	printf ("归并排序后：");
	for (int i=0;i<len_x+len_y;i++){
		printf ("%d ",answer[i]);
	}
}
int main (){
	int n,m;
	int x[max],y[max];
	scanf ("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		scanf ("%d",&x[i]);
	}
	for (int i=0;i<m;i++){
		scanf ("%d",&y[i]);
	}
	merge_sort(x,n,y,m);
	return 0;
}
/*
5 5
1 3 5 7 9
2 4 6 8 10
*/