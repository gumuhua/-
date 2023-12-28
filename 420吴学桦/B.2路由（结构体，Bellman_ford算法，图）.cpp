#include <stdio.h>
#include <string.h>
#define max 100
#define INF 10000
struct s{
	int x;
	int y;
	int length;
}H[max];
int len_min[max];
int point[max];
void cpy(int len_min[],int point[],int n){
	for (int i=1;i<=n;i++){
		point[i]=len_min[i];
	}
}
void Bell_Ford(int n,int m,int a){
    memset(len_min,0x3f,sizeof(len_min));
    len_min[a]=0; 
    for (int i=1;i<=n;i++){
    	cpy(len_min,point,n);   //防止串联
    	for (int j=1;j<=m;j++){
    		int x=H[j].x;
		int y=H[j].y;
		int length=H[j].length;
    		if ((point[x]+length)<len_min[y]){
    			len_min[y]=point[x]+length;
		}
        }
    }
}
int main(){
	int n,m;
	printf ("输入节点个数和边数：");
    scanf("%d %d",&n,&m);
    printf ("输入节点之间的关系(节点x 节点y 权值)：\n");
    for (int i=1;i<=m;i++) {
        scanf("%d %d %d",&H[i].x,&H[i].y,&H[i].length);
    }
    int a;
    printf ("输入源点：");
    scanf ("%d",&a);
    Bell_Ford(n,m,a);
    for (int i=1;i<=n;i++){
	    printf ("%d到%d最短路径：",a,i);
    	if (len_min[i]<INF)
    	printf ("%d\n",len_min[i]);
    	else
    	printf ("INF\n");
	}
    return 0;
}
/*
5 7
1 3 5
2 4 3
3 5 -2
4 1 -4
4 3 5
5 1 -3
5 4 5
*/