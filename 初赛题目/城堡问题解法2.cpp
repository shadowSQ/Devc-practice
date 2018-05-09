#include <stdio.h>
#include <iostream>
#include<string.h>
#include <stdlib.h>
using namespace std;
int huihuanflag = 0;
int endflag= 0;
int MONEY= 0 ;
int notequl(int *shuzu,int n)
{	
int i,j;
int flag = 1;

		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(shuzu[i]==shuzu[j])
			{
				flag =0;
				break;
			}	
				
			}		
		}
return flag;
	
}
int shuzujia1(int *shuzu,int n,int max){
	int i,j;
	if(shuzu[n-1]!=(max))
	shuzu[n-1]++;
	else
	{
		for(i=n-2;i>=0;i--)
		{
			if(shuzu[i]!=max)
			{
				shuzu[i]++;
				
				for(j=i;j<=n-1;j++)
				shuzu[j] = 0;
			
			}
		}
	
	}
}

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;//杩欐槸浠庡皬鍒板ぇ鎺掑簭锛岃嫢鏄粠澶у埌灏忔敼鎴愶細 return *(int *)b-*(int *)a;
}

int notinex(int j,int *except,int n){
	
	int flag = 1;
	//1琛ㄧず涓嶅啀鏁扮粍閲岄潰
	int i; 
	for(i=0;i<n;i++)
	{
		if(j==except[i])
		flag = 0;
	}
	return flag;
}
int notend(int *shuzu,int roads,int n){
	int i;
	int  flag = 0;
	for(i=0;i<n;i++)
	{
		if(shuzu[i]!=roads)
		flag = 1;//1琛ㄧず鏈粨鏉?
	} 
	return flag;
}
int iscomeback(int (*newroadcoins)[3],int n)//n琛岀殑涓夊垪鏁扮粍 
{
//0琛ㄧず鏈粨鏉?1琛ㄧず宸茬粡缁撴潫
//

int intflag = 1;
	int i ,j;
	int startpoint = 0;
	int duibi[n];
	int except[n];
	int count=0;
	int countex=0;
	int tempn = n; 
/*	for(i=0;i<n;i++)
	{ 
	printf("\n");
	printf("new[0]%d ",newroadcoins[i][0]);
	printf("new[1]%d ",newroadcoins[i][1]);
	printf("new[2]%d",newroadcoins[i][2]);
	printf("\n");
	}
	*/
	int ikkkk = 0;
	
	for(i=0;i<n;i++)
	{ 
	except[i] = -1;
	}
		
	//鍒ゆ柇瀛樺湪鍥炵幆锛?
	 
	for(ikkkk=0;ikkkk<tempn;ikkkk++)
	{ 
	//璧风偣閬嶅巻
	for(i=0;i<n;i++)
	{ 
	except[i] = -1;
	}
	count = 0;
	 startpoint = ikkkk;
	 duibi[0] = ikkkk;
//	 printf("\n");
//		printf("startT ikkkk:%d \n",ikkkk);
//		printf("\n");
	 count++;
	 intflag = 1;
	countex = 0;
	 while(intflag==1&&countex!=n)// while
	 {
	 	intflag = 0;
//	 	for(i=0;i<n;i++)
//		{ 
//		printf("\n");
//		printf("except[%d] :%d \n",i,except[i]);
//		printf("\n");
//		}
	 
	 	for(j=0;j<n;j++)
		{ 
		if(notinex(j,except,n)!=1)
		continue;
		
//		printf("\n");
//		printf("j:%d \n",j);
//		printf("\n");
		 if(newroadcoins[j][0]== duibi[count-1])
		 {
		 	duibi[count]=newroadcoins[j][1];
//		 	printf(" duibi[%d]:%d\n",count,duibi[count]);
		 	count++;
		 	except[countex++] = j;
		 	intflag = 1;//zhaodaole 
		 	break;
		 }
		 if(newroadcoins[j][1]== duibi[count-1])
		 {
			duibi[count]=newroadcoins[j][0];
//			printf(" duibi[%d]:%d\n",count,duibi[count]);
		 	count++;
		 	except[countex++] = j;
		 	intflag = 1;//zhaodaole 
		 	break;
		 }
		if(notequl(duibi,count)!=1) 
		{
			huihuanflag = 1;
			break;
		}
		 
		 	
		}//FOR
		
		if(huihuanflag==1)
		break;		
	 }//while

		if(intflag==1&&countex==n&&duibi[0]!=duibi[count])//鏃犲洖鐜紝骞朵笖 
		{
			//缁撹处鍟?
			int xmoney=0;
			for(i=0;i<n;i++)
			{ 
			xmoney += newroadcoins[i][2]; 
			}
			if(MONEY<xmoney)
			MONEY = xmoney;
				
		}
	 if(endflag == 1)
	 {
//	printf("nOVER");
	break;
	 }
	 
	}
		
		
}
int notinshuzu(int e,int *shuzu,int n)
{
	int i;
	int flag = 1;//1琛ㄧずbu 鍦ㄩ噷闈?
	for(i=0;i<n;i++)
	{
		if(shuzu[i]==e)
		flag = 0;//0琛ㄧず鍦ㄩ噷闈?
	} 
	return flag;
	
}
int maxcoin(int (*orderroadcoins)[3],int roads,int citys){
	
	
	if(roads<citys)
	{
		int i;
		for(i=0;i<roads;i++)
		MONEY += orderroadcoins[i][2];
	}

	
	
	int i,j;
	int mincoins = 0;//姹傚嚭鏈€灏忛噾甯佺粍鍚堟暟锛岀劧鍚庨亶鍘?
	int zuheshu = roads-citys+1;
	int newroadcoins[roads][3];//杩涘幓鍥炵幆澶勭悊鐨勬暟缁?
	int count=0;
	
	int tempzuheshu = zuheshu;
	
	int shuzu[tempzuheshu];
	for(i=0;i<zuheshu;i++)
	shuzu[i]=0;
	
	while(tempzuheshu--)
	{
		if(endflag ==1)
		{
			
		break;	
		}
		 	
		 	
		 while(notend(shuzu,roads-1,zuheshu))//当类型未结束 
		 {
		 	
		 		if(huihuanflag ==1)
		 	{
		 		huihuanflag =0;
		 		//jia1
		 		if(shuzu[zuheshu-1]!=(roads-1))
				shuzu[zuheshu-1]++;
				else
				{
					for(i=zuheshu-2;i>=0;i--)
					{
						if(shuzu[i]!=roads-1)
						{
							shuzu[i]++;
				          
							for(j=i+1;j<=zuheshu-1;j++)
							shuzu[j] = 0;
							
							break;
						}
						else
						{
							continue;
						}
					}
				}
				
			}//huihuanjieshu
		 	
		 
		 	if(notequl(shuzu,zuheshu))//当不相等时才进入 
		 	{
		
		 
///		 	printf("notequal");
///		 	printf("\n");
///			printf("shuzu:%d %d %d ",shuzu[0],shuzu[1],shuzu[2]);
//			printf("\n");
			count = 0;
			for(i=0;i<roads;i++)
			{
				if(notinshuzu(i,shuzu,zuheshu))
				{
				newroadcoins[count][0]=orderroadcoins[i][0];
				newroadcoins[count][1]=orderroadcoins[i][1];
				newroadcoins[count][2]=orderroadcoins[i][2];
				count++; 
				}	
			}
			//鍒ゆ柇鏄惁瀛樺湪鐜矾  
			iscomeback(newroadcoins,count);
		}
			//灏濊瘯閬嶅巻 
//			printf("\n");
//			printf("shuzu:%d %d %d ",shuzu[0],shuzu[1],shuzu[2]);
//			printf("\n");
		
				if(shuzu[zuheshu-1]!=(roads-1))
				shuzu[zuheshu-1]++;
				else
				{
					for(i=zuheshu-2;i>=0;i--)
					{
						if(shuzu[i]!=roads-1)
						{
							shuzu[i]++;
				          
							for(j=i+1;j<=zuheshu-1;j++)
							shuzu[j] = 0;
							
							break;
						}
						else
						{
							continue;
						}
					}
				}
		 }
		 
			
	} 
	
	

	
}
int main(){

	int T,N;
	int i;
	scanf("%d",&T);

	
	while(T--)
	{
		MONEY = 0;
		int citys;
		scanf("%d",&citys);
		
	
		
//		printf("countcitys:%d ",citys);
		int roads;
		scanf("%d",&roads);
		
//		printf("countloads:%d ",roads);
		
		int roadcoins[roads][3];
		int orderroadcoins[roads][3];
		int a[roads]; 
		int luguo[roads];
		int count=0;//閲嶆柊鎺掗噾甯侀『搴忓湴鍥撅紝鏆傛椂鐢?
		
		for(i=0;i<roads;i++)//璺繃鍒楄〃鍒濆鍖?1浠ｈ〃璧拌繃浜?
			luguo[i]=0;

	for(i=0;i<roads;i++)
	{
		scanf("%d",&roadcoins[i][0]);
		scanf("%d",&roadcoins[i][1]);
		scanf("%d",&roadcoins[i][2]);
	}
	for(i=0;i<roads;i++)//a鏁扮粍閲岄潰鏀惧叆鎺掑簭濂界殑roadcoins 
	{
		a[i] = roadcoins[i][2];
	}

	qsort(a,roads,sizeof(a[0]),cmp);//(鏁扮粍锛岄渶瑕佹帓搴忕殑鏁板瓧涓暟锛屽崟涓暟瀛楁墍鍗犲唴瀛樺ぇ灏忥紝姣旇緝鍑芥暟锛?
//	for(i=0;i<roads;i++)//a鏁扮粍閲岄潰鏀惧叆鎺掑簭濂界殑roadcoins 
//	{
//		printf("a[%d]: %d ",i,a[i]);
//	}
	
	//鎸夐噾甯佷粠灏忓埌澶ч噸鏂版帓甯價oadcoins
	 while(count<roads)
	 {
	 	for(i=0;i<roads;i++)//a鏁扮粍閲岄潰鏀惧叆鎺掑簭濂界殑roadcoins 
		{
			if(roadcoins[i][2]==a[count])
			{
			orderroadcoins[count][0]=roadcoins[i][0];
			orderroadcoins[count][1]=roadcoins[i][1];
			orderroadcoins[count][2]=roadcoins[i][2];
			count++;
			}
		
		}
	 }
	 
	 //瀹屾垚涔嬪悗鏌ョ湅
//	 	for(i=0;i<roads;i++)
//	{
//		printf("[0]%d ",orderroadcoins[i][0]);
//		printf("[1]%d",orderroadcoins[i][1]);
//		printf("[2]%d",orderroadcoins[i][2]);
//		printf("\n");
//	} 

	 
	maxcoin(orderroadcoins,roads,citys);
	 
	 printf("%d",MONEY);
	}

return 0;

}
