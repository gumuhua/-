#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 1000
typedef struct s {
    char num[max];
    char name[max];
    char addtion[max];
    struct s *next;
}node;
struct List {
    node *head;
};
void clear(struct List G[],int n) {
    for (int i=0;i<n;i++) {
        G[i].head=NULL;
    }
}
int HT(char a[],int n) {
    int j=strlen(a)-2;//哈希函数，后两位取余
    int sum=0;
    for (int i=j;i<strlen(a);i++) {
        sum=sum*10+(a[i]-'0');
    }
    return sum%n;
}
void creat_list(struct List G[],int n){//拉链法
    node *p,*h,*prev;
    char num[max],name[max],addtion[max];
    for (int i=0;i<n;i++) {
        p=(node *)malloc(sizeof(node));
        p->next=NULL;
        scanf("%s %s %s",num,name,addtion);
        strcpy(p->num,num);
        strcpy(p->name,name);
        strcpy(p->addtion,addtion);
        int j=HT(p->num,n);
        h=G[j].head;
        prev=NULL;
        while (h!=NULL) {
            printf("%s与%s冲突  ", p->name, h->name);
            prev=h;
            h=h->next;
        }
        if (prev==NULL) {
            G[j].head=p;
        } else {
            prev->next=p;
        }
        printf("将%s存在G[%d]中\n", p->name, j);
    }
}
void print(struct List G[], int n) {
    for (int i=0;i<n;i++) {
        node *current=G[i].head;
        if (current!=NULL) {
            printf("G[%d]",i);
            while (current!=NULL) {
                printf(" --> %s %s %s",current->num, current->name, current->addtion);
                current=current->next;
            }
            printf("\n");
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    struct List G[n];
    clear(G, n);
    creat_list(G, n);
    printf("\n");
    print(G, n);
    return 0;
}
/*
5
12345 Wu 北京
45678 Li 福建
78913 Liu 浙江
14723 Gong 南京
25812 Zhao 山东
*/