#include <stdio.h>
#include <stdlib.h>
#define len sizeof (num)
typedef struct s{
	int data;
	struct s *next;
}num;
num *creat(){
	int n;
	num *h,*t,*p;
	h=t=NULL;
	scanf ("%d",&n);
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
	return h;
}
num* result(num **L1){
	num *h,*t,*p1,*p2;
	h=t=NULL;
	p2=*L1;
	int i=1;
	while (p2){
		if (i%2==0){
			if (h==NULL){
				h=p2;
			}else{
				t->next=p2;
			}
			t=p2;
			p1->next=p2->next;
		}else{
			p1=p2;
		}
		i++;
		p2=p2->next;
	}
	return h;
}
void print(num *L){
	num *i;
	for (i=L;i;i=i->next){
		printf ("%d ",i->data);
	}
	printf ("\n");
}
int main (){
	num *L1,*L2;
	L1=creat();
	L2=result(&L1);
	printf ("L1:");
	print(L1);
	printf ("L2:");
	print(L2);
	return 0;
}