#include <stdio.h>
#include <iostream>
#include<string.h>
#include <stdlib.h>
using namespace std;

/*��һ���Խ����Ϸ��
1.��ͼ����N���Ǳ�����ŷֱ�Ϊ0~N-1����ÿ���Ǳ��й���һ�����ӣ�
2.ĳЩ�Ǳ�֮������ͨ�ģ�������ͨ��·�ϣ���ɢ�����ɸ���ң�����������ͬ��Ҳ���ܲ�ͬ����
3.����߹����ڽ�ҵ�·֮�󣬿��Ի������·�ϵ����н�ң�ͬһ��·�߶�Σ�ֻ�е�һ�οɻ�ý�ң�

��Ϸ����
1.��ҿ��Դ�����һ���Ǳ�������
2.��ұ����õ����гǱ������ӣ�
3.����߹�������·�����ܴ��ڻ�·��
4.һ����������һ����������õ��������ӵ�·�ߣ�

�����һ���㷨������������������Ϸ����ĵ�ǰ���£�����ܻ�ȡ���Ľ�Ҹ�����

��������жԻ�·��˵����
1����·���������߹���·���д���Ȧ��ʵ�����£�
�ǻ�·��                  ��·��1-2-5-4-1���Ϊ��·
1----2    3              1----2----3
     |    |              |    |
     |    |              |    |
4----5----6              4----5----6
|    |    |              |    |
|    |    |              |    |
7    8    9              7    8----9

2����˵��1�е�·���������1-2-5-4-7-4-5����Ȼ��Ȧ������4-7��5-4�е�·�����ֻ�ܳ�һ�Σ��ظ��ߵڶ��ν�Ҳ����Ի�ȡ

����˼·��

�Ǳ���Ŀcitys
��·��Ŀroads
���ѡ���·��һ����  ֻ�� citys-1�� ��·�����ߣ�����4���Ǳ������Ҫ��4��·����ôһ����· 
 

����Ҫȥ��
roads - (citys-1) ��·��

������citys-1��·���ķ������
1.�Ƿ���ڻػ�(ֻҪ������·���Ϳ��Դ��ڻ�·) 
2.�Ƿ��������

��鷽��:�����һ�㣨ȡ0�㣩�������Ժ��ַ�ʽ������(�������⣡��)һ���ط�����ô�õ�ͼΪ����



Ϊʲô��
��Ϊ �����0����Ե�������һ���ط�����ô��������ط������Խ���������һ���ط���������еط�������ͨ�� 
Ȼ��������еط�������ͨ�ģ���ô�õ�ͼһ���޻���ע�⣬�����ȡ��ֻ��citys-1��·���������£��ų����ģ�
 
 ���� 4���Ǳ���3��·������ͨ����ô�϶������� ��û�л�·���������꣩ 


*/
int huihuanflag = 0;
int nothuihuanflag = 0;
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
int startto(int (*newroadcoins)[3],int n,int start,int to)
{

	int laststart= start; 
	int temproadcoins[n][3];
	int i; 
	int zhaodaoflag = 0;
	if(huihuanflag==1)
	return 0;
	
//	printf("\nstart:%d,to:%d\n",start,to);	
	
	if(start==to)
		{
		nothuihuanflag = 1;
//		printf("\nnothuihuanflag:%d\n",nothuihuanflag);	
		return 0;
		}
	
			for(i=0;i<n;i++)
			{
				
				temproadcoins[i][0]=newroadcoins[i][0];
				temproadcoins[i][1]=newroadcoins[i][1];
				temproadcoins[i][2]=newroadcoins[i][2];	
			}//fuzhi
			
//				for(i=0;i<n;i++)
//	{
//	printf("new[0]%d ",newroadcoins[i][0]);
//	printf("new[1]%d ",newroadcoins[i][1]);
//	printf("new[2]%d",newroadcoins[i][2]);
//		printf("\n");
//	}
	
	
//	printf("\n");		
//	printf("start:%d",start);
		
//	printf("\nhuihuanflag:%d\n",huihuanflag);	
	
	int tempstart;
				for(i=0;i<n;i++)
			{	
				
			
				if(start==temproadcoins[i][0])
				{
				zhaodaoflag = 1;
				tempstart=temproadcoins[i][1];
				temproadcoins[i][0]=-1;
				temproadcoins[i][1]=-1;;	
							
				startto(temproadcoins,n,tempstart,to);
				}
				if(start==temproadcoins[i][1])
				{
				zhaodaoflag = 1;
						tempstart=temproadcoins[i][0];
				temproadcoins[i][0]=-1;
				temproadcoins[i][1]=-1;
				
				startto(temproadcoins,n,tempstart,to);
				

				}
				temproadcoins[i][0]=newroadcoins[i][0];
				temproadcoins[i][1]=newroadcoins[i][1];
				temproadcoins[i][2]=newroadcoins[i][2];	
			}
			
//			printf("找完了一遍\n");	
			
				if(zhaodaoflag == 1)
				{
//				printf("找到�?");		
	//			printf("laststart�?%d\n",laststart);	
//				printf("t�?%d\n",to);	
				if(laststart==to)
				{
				nothuihuanflag = 1;
//				printf("\nnothuihuanflag:%d\n",nothuihuanflag);	
				return 0;
				}
				}		
			if(zhaodaoflag == 0)
			{
//				printf("\nmeibaodaoTIAOGUO\n",start,to);
				if(start!=to)
				{
				
				return 0;
				}
			}
		
		return 0;
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
    return *(int *)a-*(int *)b;//鏉╂瑦妲告禒搴＄毈閸掓澘銇囬幒鎺戠碍閿涘矁瀚㈤弰顖欑矤婢堆冨煂鐏忓繑鏁奸幋鎰剁�?return *(int *)b-*(int *)a;
}

int notinex(int j,int *except,int n){
	
	int flag = 1;
	//1鐞涖劎銇氭稉宥呭晙閺佹壆绮嶉柌宀勬桨
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
		flag = 1;//1鐞涖劎銇氶張顏嗙波閺?
	} 
	return flag;
}
int iscomeback(int (*newroadcoins)[3],int n,int citys)//n鐞涘瞼娈戞稉澶婂灙閺佹壆�?
{
//0鐞涖劎銇氶張顏嗙波閺?1鐞涖劎銇氬鑼病缂佹挻�?
//HUIHUAN

	int intflag = 1;
	int i ,j;
	int startpoint = 0;
	int duibi[n];
	int except[n];
	int count=0;
	int countex=0;
	int tempn = citys; 

	int smallHUIHUANFLAG=0;	
//	for(i=0;i<n;i++)
//	{
//	printf("new[0]%d ",newroadcoins[i][0]);
//	printf("new[1]%d ",newroadcoins[i][1]);
//	printf("new[2]%d",newroadcoins[i][2]);
//		printf("\n");
//	}
//		printf("\n");
	int ikkkk = 0;
	
	for(i=0;i<n;i++)
	{ 
	except[i] = -1;
	}
		
	//閸掋倖鏌囩€涙ê婀崶鐐靛箚閿?
	
	 huihuanflag=0;//假设没有回环 
	 int start = 0;
	for(ikkkk=0;ikkkk<tempn;ikkkk++)
	{ 
//	startto(int (*newroadcoins)[3],int n,int start,int to);
		if(ikkkk!=start)
		{
//				printf("IKKKK:%d\n",ikkkk);
			 startto(newroadcoins,n,start,ikkkk);
		 	 if(nothuihuanflag == 1)//�����0���ߵ���һ�����ߵ�ͨ ���������һ����� 
		 	 						//���0����ͨ��ȫ����˵���޻ػ� 
		 	 {
		 	 	nothuihuanflag = 0;
		 	 }
		 	 else//����߲�ͨ˵�����ڻ�· 
		 	  {
	//	 	  		printf("\n");
	//	 	  		printf("\n");
//		 	  		printf("MEILUKEYIDAO");
	//	 	  		printf("\n");
		 	 	huihuanflag =1;
		 	 	break;
		 	 	}
		 	 
		}
		
	 
		 //一旦一个地方走不到，那就gg 
//	 	for(i=0;i<n;i++)
//		{ 
//		printf("\n");
//		printf("except[%d] :%d \n",i,except[i]);
//		printf("\n");
//		}
//		printf("\n");
//		printf("j:%d \n",j);
//		printf("\n");
	
		}//FOR	
	
		if(huihuanflag == 0)//閺冪姴娲栭悳顖ょ礉楠炴湹�?
		{
//					printf("\n");
//		 	  		printf("\n");
//		 	  		printf("huihuanflag==0!!!!");
//		 	  		printf("\n");
			//缂佹捁澶勯崯?
			huihuanflag==1;
			int xmoney=0;
			for(i=0;i<n;i++)
			{ 
			xmoney += newroadcoins[i][2]; 
			}
			if(MONEY<xmoney)
			MONEY = xmoney;
//				printf("\n");
//		 	  		printf("\n");
//		 	  		printf("MONEY:%d",MONEY);
//		 	  		printf("\n");
				
		}
	
}
int notinshuzu(int e,int *shuzu,int n)
{
	int i;
	int flag = 1;//1鐞涖劎銇歜u 閸︺劑鍣烽棃?
	for(i=0;i<n;i++)
	{
		if(shuzu[i]==e)
		flag = 0;//0鐞涖劎銇氶崷銊╁櫡闂?
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
	int mincoins = 0;//濮瑰倸鍤張鈧亸蹇涘櫨鐢胶绮嶉崥鍫熸殶閿涘瞼鍔ч崥搴ㄤ憾閸?
	int zuheshu = roads-citys+1;
	int newroadcoins[roads][3];//鏉╂稑骞撻崶鐐靛箚婢跺嫮鎮婇惃鍕殶�?
	int count=0;
	
	int tempzuheshu = zuheshu;
	
	int shuzu[tempzuheshu];
	for(i=0;i<zuheshu;i++)
	shuzu[i]=0;
	
	while(tempzuheshu--)
	{
	
		 	
		 	
		 while(notend(shuzu,roads-1,zuheshu))//褰撶被鍨嬫湭缁撴�?
		 {
		 	
	/*	 		if(huihuanflag ==1)
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
				continue;
			}//huihuanjieshu
		 */
		 
		 	if(notequl(shuzu,zuheshu))//褰撲笉鐩哥瓑鏃舵墠杩涘叆 
		 	{
		
		 
///		 	printf("notequal");
//		 	printf("\n");
	//		printf("shuzu:%d %d %d ",shuzu[0],shuzu[1],shuzu[2]);
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
			//閸掋倖鏌囬弰顖氭儊鐎涙ê婀悳顖濈�? 
			iscomeback(newroadcoins,count,citys);
		}
			//鐏忔繆鐦柆宥呭�?
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
		int count=0;//闁插秵鏌婇幒鎺楀櫨鐢線銆庢惔蹇撴勾閸ユ拝绱濋弳鍌涙閻?
		
		for(i=0;i<roads;i++)//鐠侯垵绻冮崚妤勩€冮崚婵嗩潗�?1娴狅綀銆冪挧鎷岀箖娴?
			luguo[i]=0;

	for(i=0;i<roads;i++)
	{
		scanf("%d",&roadcoins[i][0]);
		scanf("%d",&roadcoins[i][1]);
		scanf("%d",&roadcoins[i][2]);
	}
	for(i=0;i<roads;i++)//a閺佹壆绮嶉柌宀勬桨閺€鎯у弳閹烘帒绨總鐣屾畱roadcoins 
	{
		a[i] = roadcoins[i][2];
	}

	qsort(a,roads,sizeof(a[0]),cmp);//(閺佹壆绮嶉敍宀勬付鐟曚焦甯撴惔蹇曟畱閺佹澘鐡ф稉顏呮殶閿涘苯宕熸稉顏呮殶鐎涙澧嶉崡鐘插敶鐎涙ê銇囩亸蹇ョ礉濮ｆ棁绶濋崙鑺ユ殶�?
//	for(i=0;i<roads;i++)//a閺佹壆绮嶉柌宀勬桨閺€鎯у弳閹烘帒绨總鐣屾畱roadcoins 
//	{
//		printf("a[%d]: %d ",i,a[i]);
//	}
	
	//閹稿鍣剧敮浣风矤鐏忓繐鍩屾径褔鍣搁弬鐗堝笓鐢児oadcoins
	 while(count<roads)
	 {
	 	for(i=0;i<roads;i++)//a閺佹壆绮嶉柌宀勬桨閺€鎯у弳閹烘帒绨總鐣屾畱roadcoins 
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
	 
	 //鐎瑰本鍨氭稊瀣倵閺屻儳婀?
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
