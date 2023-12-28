#include <stdio.h>
#define max 1000
typedef struct {
	int r;
	int c;
	int data;
}Tup;
int input(Tup G[],int n){
	int t=0,x;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf ("%d",&x);
			if (x){
				G[t].r=i;
				G[t].c=j;
				G[t].data=x;
				t++;
			}
		}
	}
	return t;
}
void ChengFa(Tup A[],int num_A,Tup B[],int num_B){
	Tup C[max];
	int t=0;
	for (int i=0;i<num_A;i++){
		for (int j=0;j<num_B;j++){
			if (A[i].c==B[j].r){
				C[t].r=A[i].r;
				C[t].c=B[j].c;
				C[t].data=A[i].data*B[j].data;
				t++;
			}else{
				continue;
			}
		}
	}
	printf ("乘法结果：\n");
	for (int i=0;i<t;i++){
		printf ("r:%d c:%d data:%d\n",C[i].r,C[i].c,C[i].data);
	}
}
void JiaFa(Tup A[],int num_A,Tup B[],int num_B){
	Tup C[max];
	int t=0,i=0,j=0;
		while (i<num_A&&j<num_B){
			if (A[i].r<B[j].r){
				C[t].r=A[i].r;
				C[t].c=A[i].c;
				C[t].data=A[i].data;
				t++;
				i++;
			}else if (A[i].r==B[j].r){
				if (A[i].c<B[j].c){
					C[t].r=A[i].r;
					C[t].c=A[i].c;
					C[t].data=A[i].data;
					t++;
					i++;
				}else if (A[i].c==B[j].c){
					C[t].r=A[i].r;
					C[t].c=A[i].c;
					C[t].data=A[i].data+B[i].data;
					t++;
					i++;
					j++;
				}else{
					C[t].r=B[j].r;
					C[t].c=B[j].c;
					C[t].data=B[j].data;
					t++;
					j++;
				}
			}else{
				C[t].r=B[j].r;
				C[t].c=B[j].c;
				C[t].data=B[j].data;
				t++;
				j++;
			}
		}
	if (i>=num_A){
		while (j<num_B){
			C[t].r=B[j].r;
			C[t].c=B[j].c;
			C[t].data=B[j].data;
			t++;
			j++;
		}
	}
	if (j>=num_B){
		while (i<num_A){
			C[t].r=A[i].r;
			C[t].c=A[i].c;
			C[t].data=A[i].data;
			t++;
			i++;
		}
	}
	printf ("加法结果：\n");
	for (int k=0;k<t;k++){
		printf ("r:%d c:%d data:%d\n",C[k].r,C[k].c,C[k].data);
	}
}
int main (){
	Tup A[max],B[max],sum[max],C[max];
	int n,num_A,num_B;
	scanf ("%d",&n);
	num_A=input(A,n);
	num_B=input(B,n);
	ChengFa(A,num_A,B,num_B);
	JiaFa(A,num_A,B,num_B);
	return 0;
}
