#include <stdio.h>
int main (){
	int price;
	scanf ("%d",&price);
	int coin[4]={25,10,5,1};
	int i=0,num=0;
	while (1){
		price=price-coin[i];
		if (price<0){
			if (num){
				printf ("%d个%d分 ",num,coin[i]);
				num=0;
			}
			price=price+coin[i];
			i++;
		}else if (price>0){
			num++;
		}else{
			num++;
			printf ("%d个%d分 ",num,coin[i]);
			break;
		}
	}
	return 0;
}