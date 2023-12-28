#include <stdio.h>
#define max 1000
struct s{
	int x;
	int y;
	int weight;
}H[max];
int path[max]={0};
int len_max[max]={0};
void print_maxrole(int n){
	if (n==0){
		printf("0 ");
		return;
	}else{
		print_maxrole(path[n]);
		printf("%d ",n);
	}
}
void key_role(struct s H[],int n,int m){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			int x=H[j].x;
			int y=H[j].y;
			int weight=H[j].weight;
			if (weight+len_max[x]>len_max[y]){
				path[y]=x;
				len_max[y]=weight+len_max[x];
			}
		}
	}
	printf("关键路径是：");
	print_maxrole(n);
}

int main (){
	int n,m;
	scanf ("%d %d",&n,&m);
	for (int i=0;i<m;i++){
		scanf ("%d %d %d",&H[i].x,&H[i].y,&H[i].weight);
	}
	key_role(H,n,m);
	return 0;
}
