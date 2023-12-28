#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 1000
#define min(a,b) ((a) < (b) ? (a) : (b))
char *change(char s[]){
	static char t[max]="#";
	int j=1;
	for (int i=0;s[i]!='\0';i++){
		t[j++]=s[i];
		t[j++]='#';
	}
	t[j]='\0';
	return t;
}
/*void judge_max(char *s){//暴力中间扩展法
	int mid=0;
	int max_d=0;
	int len=strlen(s);
	int j;
	for (int i=1;s[i]!='\0';i++){
		j=0;
		while (s[i-j]==s[i+j]&&i-j>=0&&i+j<len){
			j++;
		}
		if (j>max_d){
			mid=i;
			max_d=j;
		}
	}
	max_d--;
	printf ("最长回文子序列是：");
	for (int i=mid-max_d;i<=mid+max_d;i++){
		if (s[i]!='#'){
			printf("%c",s[i]);
		}
	}
}*/
int f(char *s){ //判断字符串是否回文
	int i=0;
	int j=strlen(s)-1;
	while (i<j){
		if (s[i]!=s[j]){
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}
void Manacher(char *ch,char* s){
	int len=strlen(s);
	int right=0,mid=0,ans=0;
	int p[1000];
	for (int i=0;i<len;i++) {
    	p[i]=0;
	}
	for (int i=1;i<len-1;i++) {
    	if (i<right){
      		p[i]=(right-i)<p[2*mid-i]?(right-i):p[2*mid-i];
    	}else{
        	p[i] = 1;
    	}
    	while (s[i+p[i]]==s[i-p[i]]) {
        	p[i]++;
    	}
    	if ((i+p[i])>right) {
        	right=i+p[i];
        	mid=i;
    	}
    	ans=ans>(p[i]-1)?ans:(p[i]-1);//得到回文字符串长度
	}
	for (int i=0;ch[i]!='\0';i++){
		char t[max];
		strncpy(t,ch+i,ans);
		if (f(t)){ //用f判断拷贝的字符串是否回文
			printf("(Manacher)最长回文子序列是：");
			puts(t);
			break;
		}
	}
}

int main (){
	char ch[max];
	gets(ch);
	char *s;
	s=change(ch);
//	judge_max(s);
	Manacher(ch,s);
	return 0;
}