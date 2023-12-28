#include <stdio.h>
#include <string.h>
#define max 100
typedef struct s{
	char data[max];
	int top;
}STACK;
STACK stack;
void clear(){
	stack.top=-1;
}
char pop(){
	char c=stack.data[stack.top];
	stack.top--;
	return c;
}
void push(char c){
	stack.top++;
	stack.data[stack.top]=c;
}
bool judge(char *b,char *c){
	if (strcmp(c,b)==0){
		return true;
	}else{
		return false;
	}
}
int main (){
	clear();
	char a[max],b[max],c[max];
	gets(a);
	gets(b);
	for (int i=0;a[i]!='\0';i++){
		push(a[i]);
	}
	int j=0;
	while (stack.top!=-1){
		c[j]=pop();
		j++;
		
	}
	c[j]='\0';
	if (judge(b,c)){
		printf ("是合法的出栈序列");
	}else{
		printf ("不是合法的出栈序列");
	}
	return 0;
}