#include <stdio.h>
#include <iostream>
#include<string.h>
#include <stdlib.h>
using namespace std;

/*有一个吃金币游戏：
1.地图中有N个城堡（编号分别为0~N-1），每个城堡中挂着一面旗子；
2.某些城堡之间是连通的，在其连通的路上，分散着若干个金币（个数可能相同，也可能不同）；
3.玩家走过存在金币的路之后，可以获得这条路上的所有金币，同一条路走多次，只有第一次可获得金币；

游戏规则：
1.玩家可以从任意一个城堡出发；
2.玩家必须拿到所有城堡的旗子；
3.玩家走过的所有路，不能存在环路；
4.一定存在至少一条能让玩家拿到所有旗子的路线；

请设计一个算法，计算在遵守以上游戏规则的的前提下，最多能获取到的金币个数。

补充规则中对环路的说明：
1、环路就是最终走过的路径中存在圈，实例如下：
非环路：                  环路：1-2-5-4-1则成为环路
1----2    3              1----2----3
     |    |              |    |
     |    |              |    |
4----5----6              4----5----6
|    |    |              |    |
|    |    |              |    |
7    8    9              7    8----9

2、如说明1中的路径，玩家走1-2-5-4-7-4-5，虽然无圈，但是4-7、5-4中的路径金币只能吃一次，重复走第二次金币不可以获取

解题思路：

城堡数目citys
道路数目roads
最后选择的路径一定是  只在 citys-1条 道路上面走，比如4个城堡，如果要走4条路，那么一定环路 
 

所以要去除
roads - (citys-1) 条路径

对所有citys-1条路径的方案检查
1.是否存在回环(只要有两条路，就可以存在环路) 
2.是否可以走完

检查方法:如果从一点（取0点）（无论以何种方式）可以(到达任意！！)一个地方，那么该地图为正解



为什么？
因为 如果从0点可以到达任意一个地方，那么其他任意地方都可以借助它到另一个地方，因而所有地方都是连通得 
然后，如果所有地方都是连通的，那么该地图一定无环（注意，这个是取（只走citys-1条路径的条件下）才成立的）
 
 比如 4个城堡，3条路，都连通，那么肯定是正解 （没有环路，可以走完） 


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
			
//			printf("鎵惧畬浜嗕竴閬峔n");	
			
				if(zhaodaoflag == 1)
				{
//				printf("鎵惧埌浜?");		
	//			printf("laststart锛?%d\n",laststart);	
//				printf("t锛?%d\n",to);	
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
    return *(int *)a-*(int *)b;//閺夆晜鐟﹀Σ鍛婄鎼达紕姣堥柛鎺撴緲閵囧洭骞掗幒鎴犵闁挎稑鐭佺�氥垽寮伴娆戠煠濠㈠爢鍐ㄧ厒閻忓繐绻戦弫濂稿箣閹板墎绐?return *(int *)b-*(int *)a;
}

int notinex(int j,int *except,int n){
	
	int flag = 1;
	//1閻炴稏鍔庨妵姘▔瀹ュ懎鏅欓柡浣瑰缁秹鏌屽畝鍕〃
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
		flag = 1;//1閻炴稏鍔庨妵姘跺嫉椤忓棛娉㈤柡?
	} 
	return flag;
}
int iscomeback(int (*newroadcoins)[3],int n,int citys)//n閻炴稑鐬煎▓鎴炵▔婢跺﹤鐏欓柡浣瑰缁?
{
//0閻炴稏鍔庨妵姘跺嫉椤忓棛娉㈤柡?1閻炴稏鍔庨妵姘啅閼碱剛鐥呯紓浣规尰濞?
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
		
	//闁告帇鍊栭弻鍥┾偓娑櫭﹢顏堝炊閻愰潧绠氶柨?
	
	 huihuanflag=0;//鍋囪娌℃湁鍥炵幆 
	 int start = 0;
	for(ikkkk=0;ikkkk<tempn;ikkkk++)
	{ 
//	startto(int (*newroadcoins)[3],int n,int start,int to);
		if(ikkkk!=start)
		{
//				printf("IKKKK:%d\n",ikkkk);
			 startto(newroadcoins,n,start,ikkkk);
		 	 if(nothuihuanflag == 1)//如果从0点走到另一个点走得通 ，则测试下一组组合 
		 	 						//如果0点走通了全部，说明无回环 
		 	 {
		 	 	nothuihuanflag = 0;
		 	 }
		 	 else//如果走不通说明存在环路 
		 	  {
	//	 	  		printf("\n");
	//	 	  		printf("\n");
//		 	  		printf("MEILUKEYIDAO");
	//	 	  		printf("\n");
		 	 	huihuanflag =1;
		 	 	break;
		 	 	}
		 	 
		}
		
	 
		 //涓�鏃︿竴涓湴鏂硅蛋涓嶅埌锛岄偅灏眊g 
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
	
		if(huihuanflag == 0)//闁哄啰濮村ú鏍偝椤栥倗绀夋鐐存构缁?
		{
//					printf("\n");
//		 	  		printf("\n");
//		 	  		printf("huihuanflag==0!!!!");
//		 	  		printf("\n");
			//缂備焦鎹佹径鍕疮?
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
	int flag = 1;//1閻炴稏鍔庨妵姝渦 闁革负鍔戦崳鐑芥?
	for(i=0;i<n;i++)
	{
		if(shuzu[i]==e)
		flag = 0;//0閻炴稏鍔庨妵姘跺捶閵娾晛娅￠梻?
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
	int mincoins = 0;//婵懓鍊搁崵顓㈠嫉閳ь剛浜歌箛娑樻閻㈩垯鑳剁划宥夊触閸喐娈堕柨娑樼灱閸斞囧触鎼淬劋鎲鹃柛?
	int zuheshu = roads-citys+1;
	int newroadcoins[roads][3];//閺夆晜绋戦獮鎾诲炊閻愰潧绠氬璺哄閹﹪鎯冮崟顒佹缂?
	int count=0;
	
	int tempzuheshu = zuheshu;
	
	int shuzu[tempzuheshu];
	for(i=0;i<zuheshu;i++)
	shuzu[i]=0;
	
	while(tempzuheshu--)
	{
	
		 	
		 	
		 while(notend(shuzu,roads-1,zuheshu))//瑜版挾琚崹瀣弓缂佹挻娼?
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
		 
		 	if(notequl(shuzu,zuheshu))//瑜版挷绗夐惄鍝ョ搼閺冭埖澧犳潻娑樺弳 
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
			//闁告帇鍊栭弻鍥及椤栨碍鍎婇悗娑櫭﹢顏堟偝椤栨繄鐔? 
			iscomeback(newroadcoins,count,citys);
		}
			//閻忓繑绻嗛惁顖炴焼瀹ュ懎鍧?
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
		int count=0;//闂佹彃绉甸弻濠囧箳閹烘娅ㄩ悽顖欑窔閵嗗孩鎯旇箛鎾村嬀闁搞儲鎷濈槐婵嬪汲閸屾稒顦ч柣?
		
		for(i=0;i<roads;i++)//閻犱警鍨电换鍐礆濡ゅ嫨鈧啴宕氬┑鍡╂綏闁?1濞寸媴缍�閵嗗啰鎸ч幏宀�绠栧ù?
			luguo[i]=0;

	for(i=0;i<roads;i++)
	{
		scanf("%d",&roadcoins[i][0]);
		scanf("%d",&roadcoins[i][1]);
		scanf("%d",&roadcoins[i][2]);
	}
	for(i=0;i<roads;i++)//a闁轰焦澹嗙划宥夋煂瀹�鍕〃闁衡偓閹冨汲闁圭儤甯掔花顓熺附閻ｅ本鐣眗oadcoins 
	{
		a[i] = roadcoins[i][2];
	}

	qsort(a,roads,sizeof(a[0]),cmp);//(闁轰焦澹嗙划宥夋晬瀹�鍕粯閻熸洑鐒︾敮鎾存償韫囨洘鐣遍柡浣规緲閻⊙勭▔椤忓懏娈堕柨娑樿嫰瀹曠喐绋夐鍛閻庢稒顨嗘晶宥夊础閻樻彃鏁堕悗娑櫭妵鍥╀焊韫囥儳绀夋慨锝嗘缁舵繈宕欓懞銉︽闁?
//	for(i=0;i<roads;i++)//a闁轰焦澹嗙划宥夋煂瀹�鍕〃闁衡偓閹冨汲闁圭儤甯掔花顓熺附閻ｅ本鐣眗oadcoins 
//	{
//		printf("a[%d]: %d ",i,a[i]);
//	}
	
	//闁圭ǹ顦甸崳鍓ф暜娴ｉ鐭ら悘蹇撶箰閸╁本寰勮閸ｆ悂寮悧鍫濈瑩閻㈩垰鍏恛adcoins
	 while(count<roads)
	 {
	 	for(i=0;i<roads;i++)//a闁轰焦澹嗙划宥夋煂瀹�鍕〃闁衡偓閹冨汲闁圭儤甯掔花顓熺附閻ｅ本鐣眗oadcoins 
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
	 
	 //閻庣懓鏈崹姘▕鐎ｎ亝鍊甸柡灞诲劤濠�?
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
