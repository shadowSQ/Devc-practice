//八皇后算法
//描述：两个皇后在其横线 竖线 以及 斜线上都不能共存 ，问8个皇后棋子在8*8棋盘上有多少种共存的摆法
#include <stdio.h>
int count = 0;

int notDanger(int row,int j,int (*chess)[8])
{
	//判断上下斜线方向是否有皇后
	int i;
	int flag;
	int k; 
	//判断列方向 
	for(i=0;i<8;i++)
	{
		if(chess[i][j]==1)
		return 0;
		
	} 
	//判断左上方
	 for(i = row,k = j;i>=0&&k>= 0;i--,k--) 
	 {
	 	if(chess[i][k]==1)
		return 0;
	 }
	 //
/*	 for(i = row,k = j;i<8&&k<8;i++,k++) 
	 {
	 	if(chess[i][k]==1)
		return 0;
	 }
	 //
	 for(i = row,k = j;i<8&&k>=0;i++,k--) 
	 {
	 	if(chess[i][k]==1)
		return 0;
	 }
	 */
	 //
	 for(i = row,k = j;i>=0&&k<8;i--,k++) 
	 {
	 	if(chess[i][k]==1)
		return 0;
	 }
	 return 1;
	
}
//参数row是起始行
//col表示列
//chess为当前棋盘 
void chessprint(int row,int col,int (*chess)[8])
{
	int chess2[8][8],i,j;
	//复制棋盘 
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			chess2[i][j] = chess[i][j];	
		}	
	}
	if(row==8)
	{
		count++;
		printf("di %d zhong :\n",count);
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
			printf("%d ",chess2[i][j]);
			}	
			printf("\n");
		}
		printf("\n");
		
	} 
	else 
	{
		//判断这个位置是否有危险
		//如果没有危险，则可以放置，继续进行
		for (j = 0;j<8;j++)
		{
			//判断是否危险 ,如果没有危险，则 
			if(notDanger(row,j,chess))
			{
				//这一行先全部置为0 
				
				//皇后位置 置为1 
				chess2[row][j] = 1;	
				
				chessprint(row+1,8,chess2);
				
				for(i=0;i<8;i++)
				chess2[row][i] = 0;
			} 
		
		} 
	}
}
int main(){
	int chess[8][8],i,j;
	//初始化 
	for(i = 0 ;i<8;i++)
	{
		for(j = 0 ;j<8;j++)
		{
			chess[i][j] = 0;
		}
	}
	
	chessprint(0,0,chess); 
	
	return 0;
} 
