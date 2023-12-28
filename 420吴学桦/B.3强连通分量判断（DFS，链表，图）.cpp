#include <stdio.h>
#include <stdlib.h>
#define max 100
typedef struct s{
	int data;
	struct s *next;
}node;
void creat(node *head[],int n,int a[max][max]){
	node *t,*p;
	for (int i=0;i<n;i++){
		t=head[i]=NULL;
		for (int j=0;j<n;j++){
			if (a[i][j]!=0){
				p=(node *)malloc(sizeof(node));
				p->next=NULL;
				p->data=j;
				if (head[i]==NULL){
					head[i]=p;
				}else{
					t->next=p;
				}
				t=p;
			}
		}
	}
}
void print(node *head[],int n){
	for (int i=0;i<n;i++){
		node *t=head[i];
		while (t!=NULL){
			printf ("%d ",t->data);
			t=t->next;
		}
		printf ("\n");
	}
}
int visit[max]={0};
void clear(int n){
	for (int i=0;i<n;i++){
		visit[i]=0;
	}
}
void DFS(node *head[],int v){
	node *t;
	visit[v]=1;
	t=head[v];
	printf ("%d ",v);
	while (t!=NULL){
		if (visit[t->data]==0){
			DFS(head,t->data);
		}
		t=t->next;
	}
}
void judge(node *head[],int n){
	for (int i=0;i<n;i++){
		printf ("%d路径：",i);
		DFS(head,i);
		printf ("\n");
		for (int j=0;j<n;j++){
			if (visit[j]==0){
				printf ("NO");
				return ;
			}
		}
		clear(n);
	}
	printf("YES");
}
int main (){
	int n;
	node *head[max];
	int a[max][max];/*={
	{0,1,0,0,1},
	{0,0,0,1,0},
	{0,1,0,0,1},
	{1,0,1,0,0},
	{0,0,1,0,0},
	};*/
	scanf ("%d",&n);
	getchar();
	char j;
	for (int i=0;i<n;i++){
		printf ("%d->",i);
		while (scanf ("%c",&j)&&j!='\n'){
			if (j<='9'&&j>='0'){
				a[i][j-'0']=1;
			}
		}
	}

	creat(head,n,a);
	judge(head,n);
	return 0;
}