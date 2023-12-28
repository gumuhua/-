#include <stdio.h>
#include <stdlib.h>
#define len sizeof(num)
typedef struct s{
	int data;
	struct s *next;
	struct s *pre;
}num;
num *creat(){
	num *h,*t,*p;
	h=t=NULL;
	int n;
	scanf ("%d",&n);
	for (int i=0;i<n;i++){
		p=(num *)malloc(len);
		p->next=NULL;
		p->pre=NULL;
		scanf ("%d",&p->data);
		if (h==NULL){
			h=p;
		}else{
			p->pre=t;
			t->next=p;
		}
		t=p;
	}
	return h;
}
void jiaoji(num *A,num *B){
	num *h,*t,*i;
	h=t=NULL;
	while (A&&B){
		if (A->data==B->data){
			if (h==NULL){
				h=A;
			}else{
				t->next=A;
			}
			t=A;
			A=A->next;
			B=B->next;
		}else if (A->data<B->data){
			A=A->next;
		}else{
			B=B->next;
		}
	}
	printf ("交集是：");
	for (i=h;i;i=i->next){
		printf ("%d ",i->data);
	}
	printf ("\n");
}
void bingji(num *A,num *B){
	num *h,*t,*i;
	h=t=NULL;
	while (A&&B){
		if(A->data<B->data){
			if (h==NULL){
				h=A;
			}else{
				t->next=A;
			}
			t=A;
			A=A->next;
		}else if (A->data>B->data){
			if (h==NULL){
				h=B;
			}else{
				t->next=B;
			}
			t=B;
			B=B->next;
		}else{
			if (h==NULL){
				h=A;
			}else{
				t->next=A;
			}
			t=A;
			A=A->next;
			B=B->next;
		}
	}
	if (A){
		t->next=A;
	}
	if (B){
		t->next=B;
	}
	printf ("并集是：");
	for (i=h;i;i=i->next){
		printf ("%d ",i->data);
	}
	printf ("\n");
}
int main (){
	num *A,*B,*i;
	A=creat();
	B=creat();
	jiaoji(A,B);
	bingji(A,B);
	return 0;
}
