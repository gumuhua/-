#include <stdio.h>
#include <stdlib.h>
#define max 1000
typedef struct s{
	char data;
	int num;
	struct s *left;
	struct s *right;
}node;
int judge=0;
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
void print_find(node *H,char ch,char find[],int find_i){
	if (H==NULL){
		return;
	}
	find[find_i]=H->data;  //加个数组回溯
	find_i++;
	if (H->left==NULL&&H->right==NULL&&H->data==ch){
		judge=1;
	 	printf ("从根节点到%c路径为：",ch);
        for (int i=0;i<find_i;i++) {
            printf("%c ", find[i]);
        }
        printf("\n");
        return;
    }
		print_find (H->left,ch,find,find_i);	
		print_find (H->right,ch,find,find_i);
}
int main (){
	char tree[max],find[max];
	node *H,*t;
	char ch;
	int find_i=0;
	printf ("用括号法输入树：");
	gets(tree);
	H=creat_list(tree);
	printf ("输入查找叶子节点：");
	scanf("%c",&ch);
	print_find(H,ch,find,find_i);
	if (judge==0){
		printf ("%c不是叶子节点");
	}
	return 0;
}
/*
A(B(D(,G)),C(E,F))
*/