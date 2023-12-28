#include <stdio.h>
#include <string.h>
#define max 1000
struct s{
	char num[max];
	char name[max];
	char addtion[max];
	int f;
}G[max],sort[max];
void clear(struct s sort[],int n){
	for (int i=0;i<n;i++){
		sort[i].f=0;
	}
}
int HT(char a[],int n){//哈希函数，后两位取余
	int j=strlen(a)-2;
	int sum=0;
	for (int i=j;i<strlen(a);i++){
		sum=sum*10+(a[i]-'0');
	}
	return sum%n;
}
void creat_list(struct s G[],int n){
	for (int i=0;i<n;i++){
		scanf("%s %s %s",G[i].num,G[i].name,G[i].addtion);
		int j=HT(G[i].num,n);
		while (sort[j].f==1){//线性探测法
			printf ("%s与%s冲突  ",G[i].name,sort[j].name);
			j++;
		}
		printf ("将%s存在sort[%d]中\n",G[i].name,j);
		sort[j]=G[i];
		sort[j].f=1;
	}
}
void print(struct s h[],int n){
	for (int i=0;i<n+2;i++){
		if (h[i].f==1)
		printf ("sort[%d]:%s %s %s\n",i,h[i].num,h[i].name,h[i].addtion);
	}
}
int main (){
	int n;
	scanf ("%d",&n);
	clear(sort,n);
	creat_list(G,n);
	printf ("\n");
	print(sort,n);
	return 0;
}
/*
5
12345 Wu 北京
45678 Li 福建
78910 Liu 浙江
14723 Gong 南京
25812 Zhao 山东
*/