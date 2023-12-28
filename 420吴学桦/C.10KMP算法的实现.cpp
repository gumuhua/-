#include<stdio.h>
#include <string.h>
#define max 1000
void getnext(char *t,int next[]){
	int len_t=strlen(t);
	next[0]=-1;
	int j=0,k=-1;
	while (j<len_t-1){
		if (k==-1||t[j]==t[k]){
			j++;
			k++;
			next[j]=k;
		}else{
			k=next[k];
		}
	}
}
int KMP(char *t,char *s){
	int i,j,len_t,len_s;
	i=0,j=0;
	int next[max];
	getnext(t,next);
	len_t=strlen(t);
	len_s=strlen(s);
	while (j<len_t&&i<len_s){
		if (j==-1||t[j]==s[i]){
			i++;
			j++;
		}else{
			j=next[j];
		}
	}
	if (j>=len_t){
		return i-len_t;
	}else{
		return -1;
	}
}
int main (){
	char s[max],t[max];
	gets(s);
	gets(t);
	printf ("子串在目标串中的位置是s[%d]开始",KMP(t,s));
	return 0;
}