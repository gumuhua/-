#include <stdio.h>
#define max 100
int main (){
	int data[max];
	int num=0,result=1,n;
	scanf ("%d",&n);
	for (int i=0;i<n;i++){
		scanf ("%d",&data[i]);
	}
	int f;
	for (int i=1;i<n;i++){
		if (data[i-1]==data[i]){
			num++;
			result=0;
		}else if (data[i-1]<data[i]){
			if (f==1){
				num++;
				result=0;
			}else{
				f=1;
			}
		}else{
			if (f==0){
				num++;
				result=0;
			}else{
				f=0;
			}
		}
	}
	if (result==1){
		printf ("是摆动数列");
	}else{
		printf ("不是摆动数列，需要删除%d个元素",num);
	}
	return 0;
}