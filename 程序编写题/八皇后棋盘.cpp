//�˻ʺ��㷨
//�����������ʺ�������� ���� �Լ� б���϶����ܹ��� ����8���ʺ�������8*8�������ж����ֹ���İڷ�
#include <stdio.h>
int count = 0;

int notDanger(int row,int j,int (*chess)[8])
{
	//�ж�����б�߷����Ƿ��лʺ�
	int i;
	int flag;
	int k; 
	//�ж��з��� 
	for(i=0;i<8;i++)
	{
		if(chess[i][j]==1)
		return 0;
		
	} 
	//�ж����Ϸ�
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
//����row����ʼ��
//col��ʾ��
//chessΪ��ǰ���� 
void chessprint(int row,int col,int (*chess)[8])
{
	int chess2[8][8],i,j;
	//�������� 
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
		//�ж����λ���Ƿ���Σ��
		//���û��Σ�գ�����Է��ã���������
		for (j = 0;j<8;j++)
		{
			//�ж��Ƿ�Σ�� ,���û��Σ�գ��� 
			if(notDanger(row,j,chess))
			{
				//��һ����ȫ����Ϊ0 
				
				//�ʺ�λ�� ��Ϊ1 
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
	//��ʼ�� 
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
