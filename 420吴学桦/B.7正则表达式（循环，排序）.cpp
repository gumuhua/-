#include <stdio.h>
#include <string.h>
#define max 1000
int  compare(char *s,char *p){
	int len_s=strlen(s);
	int len_p=strlen(p);
	int f=0;
	int i=0,j=0;
	char temp;
	while (i<len_s&&j<len_p){
		if (s[i]==p[j]){
			i++;
			j++;
			continue;
		}else{
			if (f==1){
				if (temp==s[i]){
					i++;
					continue;
				}else{
					j++;
					if (p[j]==s[i]&&j<len_p){
						f=0;
						continue;
					}else{
						return 0;
					}
				}
			}else if (p[j]=='.'){
				i++;
				j++;
				continue;
			}else if (p[j]=='*'){
				if (p[j-1]=='.'){
					temp=s[i];
				}else{
					temp=p[j-1];
				}
				if (temp==s[i]){
					i++;
				}else{
					return 0;
				}
				f=1;
			}else{
				return 0;
			}
		}
	}
	if (i==len_s){
		return 1;
	}
	return 0;
}
int main (){
	char s[max],p[max];
	scanf ("%s %s",s,p);
	if (compare(s,p)){
		printf ("正则表达式：True");
	}else{
		printf ("正则表达式：Fasle");
	}
	return 0;
}