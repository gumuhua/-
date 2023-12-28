#include <stdio.h>
#include <stdlib.h>
#define max 1000
typedef struct s{
	int data;
	struct s *left;
	struct s *right;
}node;
struct number{
	int d;
	int l;
	int r;
}num[max];
void creat(node **root,struct number num[],int i){
	*root=(node *)malloc(sizeof(node));
	(*root)->left=(*root)->right=NULL;
	(*root)->data=num[i].d;
	if (num[i].l==-1&&num[i].r==-1){
		return;
	}
	if (num[i].l!=-1){
		creat(&(*root)->left,num,num[i].l);
	}
	if (num[i].r!=-1){
		creat(&(*root)->right,num,num[i].r);
	}
}
void first_print(node *root){
	if (root==NULL){
		return;
	}else{
		printf("%d ",root->data);
		first_print(root->left);
		first_print(root->right);
	}
}
void mid_print(node *root){
	if (root==NULL){
		return;
	}else{
		mid_print(root->left);
		printf("%d ",root->data);
		mid_print(root->right);
	}
}
void final_print(node *root){
	if (root==NULL){
		return;
	}else{
		final_print(root->left);
		final_print(root->right);
		printf("%d ",root->data);
	}
}
int main (){
	int n;
	node *root;
	scanf ("%d",&n);
	for (int i=1;i<=n;i++){
		scanf ("%d %d %d",&num[i].d,&num[i].l,&num[i].r);
	}
	creat(&root,num,1);
	printf("先序遍历：");
	first_print(root);
	printf("\n中序遍历：");
	mid_print(root);
	printf ("\n后序遍历：");
	final_print(root);
	
}
/*
8
1 2 3
2 4 5
3 6 -1
4 -1 -1
5 -1 -1
6 -1 7
7 8 -1
8 -1 -1
*/