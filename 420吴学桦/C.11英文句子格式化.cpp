#include<stdio.h>
#define max 1000
int main (){
	char a[max];
	int f=0;
	gets(a);
	for (int i=0;a[i]!='\0';i++){
		if (a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z'){
			f=1;
			printf ("%c",a[i]);
		}else{
			if (a[i]==' '){
				if (f==0){
					continue;
				}else{
					printf ("%c",a[i]);
					f=0;
				}
			}else{
				printf ("%c",a[i]);
				f=0;
			}

		}
	}
	return 0;
}