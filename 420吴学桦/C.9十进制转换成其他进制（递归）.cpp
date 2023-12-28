#include <stdio.h>
void print_two(int n){
	if (n==0){
		return;
	}
	print_two(n/2);
	printf ("%d",n%2);
}
void print_eight(int n){
	if (n==0){
		return;
	}
	print_eight(n/8);
	printf ("%d",n%8);
}
void print_sixteen(int n){
	if (n==0){
		return ;
	}
	print_sixteen(n/16);
	if (n%16>=10){
		printf ("%c",(n%16-10)+'A');
	}else{
		printf ("%d",n%16);
	}
}
int main (){
	int n;
	scanf ("%d",&n);
	printf ("二进制：");
	print_two(n);
	printf ("\n八进制：");
	print_eight(n);
	printf ("\n十六进制：");
	print_sixteen(n);
	return 0;
}