#include <stdio.h>
#include <stdlib.h>
#define max 100
#define INF 999
typedef struct s{
	int lenth;
	int loction;
	struct s *next;
}Node;
void clear(Node H[],int n){
	for (int i=0;i<n;i++){
		H[i].next=NULL;
	}
}
void print_node(Node H[],int n){
    for (int i=0;i<n;i++){
        printf("%d节点路径: ",i);
        Node *t=H[i].next;
        while (t!=NULL){
            printf("%d-[%d] ",t->loction,t->lenth);
            t=t->next;
        }
        printf("\n");
    }
}
void print_list(Node H[],int n){
	int a[max][max]={0};
	for (int i=0;i<n;i++){
		Node *h=H[i].next;
		while (h!=NULL){
			if (h->lenth!=0){
				a[i][h->loction]=h->lenth;
			}
			h=h->next;
		}			
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==j){
				printf ("0 ");
			}else if(a[i][j]!=0){
				printf ("%d ",a[i][j]);
			}else if (a[i][j]==0){
				printf ("INF ");
			}
		}
		printf ("\n");
	}
}
void change_1(int a[max][max],int n){
	Node H[max];
	Node *t,*p;
	clear(H,n);
	for (int i=0;i<n;i++){
		t=H[i].next;
		for (int j=0;j<n;j++){
			if (a[i][j]!=0&&a[i][j]<INF){
				p=(Node *)malloc(sizeof(Node));
				p->next=NULL;
				p->lenth=a[i][j];
				p->loction=j;
				if (H[i].next==NULL){
					H[i].next=p;
				}else{
					t->next=p;
				}
				t=p;
			}
		}
	}
	print_node(H,n);
	printf("\n");
	print_list(H,n);
}

int main (){
	int a[max][max]={
	{0,2,INF,1},
	{INF,0,2,INF},
	{1,INF,0,INF},
	{INF,2,INF,0},};
	int n=4,m=4;
	change_1(a,n);
	return 0;
}