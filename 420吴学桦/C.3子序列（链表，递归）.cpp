#include <stdio.h>
#include <stdlib.h>
#define len sizeof(num)
typedef struct s{
	int data;
	struct s *next;
}num;
num *creat(int n){
	num *h,*t,*p;
	h=t=NULL;
	for (int i=0;i<n;i++){
		p=(num *)malloc(len);
		p->next=NULL;
		scanf ("%d",&p->data);
		if (h==NULL){
			h=p;
		}else{
			t->next=p;
		}
		t=p;
	}
	t->next=h;
	return h;
}
void answer(num *h,int n,int m){
	num *p2,*p1;
	p2=h;
	int i=1;
	printf ("淘汰顺序：");
	while (n>1){
		if (i%m==0){
			printf ("%d ",p2->data);
			p1->next=p2->next;
			n--;
		}else{
			p1=p2;
		}
		i++;
		p2=p2->next;
	}
	printf ("\n最终剩余：%d\n",p2->data);
}
int main (){
	int n,m;
	num *h;
	scanf ("%d %d",&n,&m);
	h=creat(n);
	answer(h,n,m);
	return 0;
}