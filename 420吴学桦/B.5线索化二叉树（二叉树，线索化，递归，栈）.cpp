#include <stdio.h>
#include <stdlib.h>
#define max 1000
typedef struct s{
	char data;
	int time;
	int rate;
	int f_left;
	int f_right;
	struct s *left;
	struct s *right;
}node;
node *creat_list(char *tree){
	node *p,*H;
	H=NULL;
	node *stack[max];
	int top=-1;
	int f;
	int j=0;
	for (int i=0;tree[i]!='\0';i++){
		if (tree[i]=='('){
			stack[++top]=p;
			f=1;	
		}else if (tree[i]==')'){
			top--;
		}else if (tree[i]==','){
			f=2;
		}else{
			p=(node *)malloc(sizeof(node));
			p->left=p->right=NULL;
			p->data=tree[i];
			printf ("请输入%c的浇水频率和修剪时间：",p->data);
			scanf ("%d %d",&p->rate,&p->time);
			if (H==NULL){
				H=p;
			}else{
				if (f==1){
					stack[top]->left=p;
				}else{
					stack[top]->right=p;
				}
			}
		}
	}
	return H;
}
void mid_clues(node *H,node **pre){
	if (H!=NULL){
		mid_clues(H->left,pre);
		if (H->left==NULL){
			H->left=*pre;
			H->f_left=1;
		}else{
			H->f_left=0;
		}
		if ((*pre)->right==NULL){
			(*pre)->right=H;
			(*pre)->f_right=1;
		}else{
			(*pre)->f_right=0;
		}
		*pre=H;
		mid_clues(H->right,pre);
	}
}
void mid_print(node *H){
	node *root=(node *)malloc(sizeof(node));
	root->f_left=0;
	root->f_right=1;
	root->right=H;
	if (H==NULL){
		root->left=root;
	}else{
		root->left=H;
		node *pre=root;
		mid_clues(H,&pre);
		pre->right=root;
		pre->f_right=1;
		root->right=pre;
	}
	node *p=root->left;
	while (p!=root){
		while (p->f_left==0){
			p=p->left;
		}
		printf ("%c rate[%d] time[%d]\n",p->data,p->rate,p->time);
		while (p->f_right==1&&p->right!=root){
			p=p->right;
			printf ("%c rate[%d] time[%d]\n",p->data,p->rate,p->time);
		}
		p=p->right;
	}
}
int main (){
	char tree[max];
	node *root,*t,*H;
	printf ("括号法输入树：");
	gets(tree);
	H=creat_list(tree);
	mid_print(H);
	return 0;
}
/*
A(B(D(,G)),C(E,F))
1 2
3 4
5 6
7 8 
9 10
1 4
2 5
*/