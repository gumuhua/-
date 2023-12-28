#include <stdio.h>
#include <string.h>
#define max 100
int queue[max];
int len_max[max];//最长路径
int len[max][max];//存路径长
void BFS(int n,int a){
    memset(len_max,-1,sizeof(len_max[0]));
    len_max[a]=0;
    int front=0,rear=0;
    queue[rear++]=a;
    while (front<rear) {
        int t=queue[front++];
        for (int i=1;i<=n;i++){
            if (len[t][i]&&len_max[i]<len_max[t]+len[t][i]) {
                len_max[i]=len_max[t]+len[t][i];
                queue[rear++]=i;
            }
        }
    }
}
int main(){
	int n,m;
	printf ("输入节点个数和边数：");
    scanf("%d %d",&n,&m);
    int x,y,v;
    printf ("输入节点之间的关系(节点x 节点y 权值)：\n");
    for (int i=1;i<=m;i++) {
        scanf("%d %d %d",&x,&y,&v);
        len[x][y]=v;
    }
    int a,b;
    printf ("输入需要查询的两个节点：");
    scanf ("%d %d",&a,&b);
    BFS(n,a);
    if (len_max[b]>0)
    printf("%d到%d最长路径为：%d\n",a,b,len_max[b]);
    else
    printf ("%d不能到达%d点\n",a,b);
    return 0;
}
/*
5 8
1 2 1
1 4 8
1 5 7
2 4 6
2 3 2
3 5 3
4 3 4
4 5 5
*/