#include <stdio.h>
#define max 8
int queen_col[max]={0};
int number=0;
int judge(int row, int col) {
    for (int i=0;i<row;i++) {
    	//row-col是下对角线，row+col是上对角线
        if (queen_col[i]==col||row-col==i-queen_col[i]||row+col==queen_col[i]+i){
            return 0;
        }
    }
    return 1;
}
void back_queen(int row) {
    if (row==max){
    	for (int i=0;i<max;i++){
    		printf ("(%d,%d) ",i,queen_col[i]);
		}
		printf ("\n");
        number++;
        return;
    }
    for (int j=0;j<max;j++) {//j列开始
        if (judge(row, j)) {
            queen_col[row]=j;
            back_queen(row+1);
            queen_col[row]=0;
        }
    }
}
int main() {
	int i=0;
    back_queen(i);
    printf("总共%d种解法",number);
    return 0;
}