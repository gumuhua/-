#include <stdio.h>
#include <stdlib.h>
#define max 1000
typedef struct s{
	char data;
	int num;
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
			p->num=j++;
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
node* public_node(node *H,char n,char m){
	if (H==NULL||H->data==n||H->data==m){
		return H;
	}
	node *l=public_node(H->left,n,m);
	node *r=public_node(H->right,n,m);
	if(l!=NULL&&r!=NULL){
		return H;
	}else if (l==NULL){
		return r;
	}else if (r==NULL){
		return l;
	}
    return NULL;
}
int main (){
	char tree[max];
	node *H,*t;
	char n,m;
	printf ("括号法输入树：");
	gets(tree);
	H=creat_list(tree);
	printf ("输入两个节点：");
	scanf("%c %c",&n,&m);
	t=public_node(H,n,m);
	if(t!=NULL){
		printf ("%c和%c的祖先是：%c",n,m,t->data);
	}else{
		printf ("未找到！");
	}

	return 0;
}
/*
A(B(D(,G)),C(E,F))
*/