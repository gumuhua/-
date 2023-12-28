#include <stdio.h>
#include <string.h>
#define max 1000
void JiaFa(char a[],int len_a,char b[],int len_b){
	int result[max]={0};
	int x[max]={0},y[max]={0};
	for (int j=0,i=len_a-1;i>=0;j++,i--){
		x[j]=a[i]-'0';
	}
	for (int j=0,i=len_b-1;i>=0;j++,i--){
		y[j]=b[i]-'0';
	}
	for (int i=0;i<(len_a>len_b?len_a:len_b);i++){
		result[i]=x[i]+y[i];
		if (result[i]>9){
			result[i+1]+=result[i]/10;
			result[i]%=10;
		}
	}
	int n=len_a+len_b;
	while(result[n]==0&&n>0){
		n--;
	}
	printf ("加法结果：");
	for (int i=n;i>=0;i--){
		printf ("%d",result[i]);
	}
	printf ("\n");
}
int compare(char *a,int len_a,char *b,int len_b){
	char *t;
	if (len_a>len_b){
		return 0;
	}else if (len_a<len_b){
		strcpy(t,a);
		strcpy(a,b);
		strcpy(b,t);
		return 1;
	}else{
		for (int i=0;i<len_a;i++){
			if (a[i]-b[i]>0){
				return 0;
			}else if (a[i]-b[i]<0){
				strcpy(t,a);
				strcpy(a,b);
				strcpy(b,t);
				return 1;
			}else{
				continue;
			}
		}
	}
	return 0;
}
void JianFa(char a[],int len_a,char b[],int len_b){
	int result[max]={0};
	int x[max]={0},y[max]={0};
	int f=compare(a,len_a,b,len_b);
	int t;
	if (f==1){
		t=len_a;
		len_a=len_b;
		len_b=t;
	}
	for (int j=0,i=len_a-1;i>=0;j++,i--){
		x[j]=a[i]-'0';
	}
	for (int j=0,i=len_b-1;i>=0;j++,i--){
		y[j]=b[i]-'0';
	}
	for (int i=0;i<len_a;i++){
		result[i]+=x[i]-y[i];
		if (result[i]<0){
			result[i]+=10;
			result[i+1]--;
		}
	}
	int n=len_a;
	while (result[n]==0&&n>0){
		n--;
	}
	printf ("减法结果：");
	if (f==1){
		printf ("-");
	}
	for (int i=n;i>=0;i--){
		printf ("%d",result[i]);
	}
	printf ("\n");
}
void ChengFa(char a[],int len_a,char b[],int len_b){
	int result[max]={0};
	int x[max]={0},y[max]={0};
	for (int j=0,i=len_a-1;i>=0;j++,i--){
		x[j]=a[i]-'0';
	}
	for (int j=0,i=len_b-1;i>=0;j++,i--){
		y[j]=b[i]-'0';
	}
	int t;
	for (int i=0;i<len_a;i++){
		t=i;
		for (int j=0;j<len_b;j++,t++){
			result[t]+=x[i]*y[j];
		}
		if (result[i]>9){
			result[i+1]+=result[i]/10;
			result[i]%=10;
		}
	}
	int n=len_a+len_b;
	while(result[n]==0&&n>0){
		n--;
	}
	printf ("乘法结果：");
	for (int i=n;i>=0;i--){
		printf ("%d",result[i]);
	}
	printf ("\n");
}
int main (){
	char a[max],b[max];
	int len_a,len_b;
	scanf ("%s",a);
	scanf ("%s",b);
	len_a=strlen(a);
	len_b=strlen(b);
	JiaFa(a,len_a,b,len_b);
	ChengFa(a,len_a,b,len_b);//乘法先，不然减法中的compare可能交换a，b的地址
	JianFa(a,len_a,b,len_b);
	return 0;
}
/*
12345678901234567890
98765432109876543210
*/