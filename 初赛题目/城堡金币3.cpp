#include <stdio.h>
#include <iostream>
#include<string.h>
#include <stdlib.h>
using namespace std;

/*ÓÐÒ»¸ö³Ô½ð±ÒÓÎÏ·£º
1.µØÍ¼ÖÐÓÐN¸ö³Ç±¤£¨±àºÅ·Ö±ðÎª0~N-1£©£¬Ã¿¸ö³Ç±¤ÖÐ¹Ò×ÅÒ»ÃæÆì×Ó£»
2.Ä³Ð©³Ç±¤Ö®¼äÊÇÁ¬Í¨µÄ£¬ÔÚÆäÁ¬Í¨µÄÂ·ÉÏ£¬·ÖÉ¢×ÅÈô¸É¸ö½ð±Ò£¨¸öÊý¿ÉÄÜÏàÍ¬£¬Ò²¿ÉÄÜ²»Í¬£©£»
3.Íæ¼Ò×ß¹ý´æÔÚ½ð±ÒµÄÂ·Ö®ºó£¬¿ÉÒÔ»ñµÃÕâÌõÂ·ÉÏµÄËùÓÐ½ð±Ò£¬Í¬Ò»ÌõÂ·×ß¶à´Î£¬Ö»ÓÐµÚÒ»´Î¿É»ñµÃ½ð±Ò£»

ÓÎÏ·¹æÔò£º
1.Íæ¼Ò¿ÉÒÔ´ÓÈÎÒâÒ»¸ö³Ç±¤³ö·¢£»
2.Íæ¼Ò±ØÐëÄÃµ½ËùÓÐ³Ç±¤µÄÆì×Ó£»
3.Íæ¼Ò×ß¹ýµÄËùÓÐÂ·£¬²»ÄÜ´æÔÚ»·Â·£»
4.Ò»¶¨´æÔÚÖÁÉÙÒ»ÌõÄÜÈÃÍæ¼ÒÄÃµ½ËùÓÐÆì×ÓµÄÂ·Ïß£»

ÇëÉè¼ÆÒ»¸öËã·¨£¬¼ÆËãÔÚ×ñÊØÒÔÉÏÓÎÏ·¹æÔòµÄµÄÇ°ÌáÏÂ£¬×î¶àÄÜ»ñÈ¡µ½µÄ½ð±Ò¸öÊý¡£

²¹³ä¹æÔòÖÐ¶Ô»·Â·µÄËµÃ÷£º
1¡¢»·Â·¾ÍÊÇ×îÖÕ×ß¹ýµÄÂ·¾¶ÖÐ´æÔÚÈ¦£¬ÊµÀýÈçÏÂ£º
·Ç»·Â·£º                  »·Â·£º1-2-5-4-1Ôò³ÉÎª»·Â·
1----2    3              1----2----3
     |    |              |    |
     |    |              |    |
4----5----6              4----5----6
|    |    |              |    |
|    |    |              |    |
7    8    9              7    8----9

2¡¢ÈçËµÃ÷1ÖÐµÄÂ·¾¶£¬Íæ¼Ò×ß1-2-5-4-7-4-5£¬ËäÈ»ÎÞÈ¦£¬µ«ÊÇ4-7¡¢5-4ÖÐµÄÂ·¾¶½ð±ÒÖ»ÄÜ³ÔÒ»´Î£¬ÖØ¸´×ßµÚ¶þ´Î½ð±Ò²»¿ÉÒÔ»ñÈ¡

½âÌâË¼Â·£º

³Ç±¤ÊýÄ¿citys
µÀÂ·ÊýÄ¿roads
×îºóÑ¡ÔñµÄÂ·¾¶Ò»¶¨ÊÇ  Ö»ÔÚ citys-1Ìõ µÀÂ·ÉÏÃæ×ß£¬±ÈÈç4¸ö³Ç±¤£¬Èç¹ûÒª×ß4ÌõÂ·£¬ÄÇÃ´Ò»¶¨»·Â· 
 

ËùÒÔÒªÈ¥³ý
roads - (citys-1) ÌõÂ·¾¶

¶ÔËùÓÐcitys-1ÌõÂ·¾¶µÄ·½°¸¼ì²é
1.ÊÇ·ñ´æÔÚ»Ø»·(Ö»ÒªÓÐÁ½ÌõÂ·£¬¾Í¿ÉÒÔ´æÔÚ»·Â·) 
2.ÊÇ·ñ¿ÉÒÔ×ßÍê

¼ì²é·½·¨:Èç¹û´ÓÒ»µã£¨È¡0µã£©£¨ÎÞÂÛÒÔºÎÖÖ·½Ê½£©¿ÉÒÔ(µ½´ïÈÎÒâ£¡£¡)Ò»¸öµØ·½£¬ÄÇÃ´¸ÃµØÍ¼ÎªÕý½â



ÎªÊ²Ã´£¿
ÒòÎª Èç¹û´Ó0µã¿ÉÒÔµ½´ïÈÎÒâÒ»¸öµØ·½£¬ÄÇÃ´ÆäËûÈÎÒâµØ·½¶¼¿ÉÒÔ½èÖúËüµ½ÁíÒ»¸öµØ·½£¬Òò¶øËùÓÐµØ·½¶¼ÊÇÁ¬Í¨µÃ 
È»ºó£¬Èç¹ûËùÓÐµØ·½¶¼ÊÇÁ¬Í¨µÄ£¬ÄÇÃ´¸ÃµØÍ¼Ò»¶¨ÎÞ»·£¨×¢Òâ£¬Õâ¸öÊÇÈ¡£¨Ö»×ßcitys-1ÌõÂ·¾¶µÄÌõ¼þÏÂ£©²Å³ÉÁ¢µÄ£©
 
 ±ÈÈç 4¸ö³Ç±¤£¬3ÌõÂ·£¬¶¼Á¬Í¨£¬ÄÇÃ´¿Ï¶¨ÊÇÕý½â £¨Ã»ÓÐ»·Â·£¬¿ÉÒÔ×ßÍê£© 


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
			
//			printf("æ‰¾å®Œäº†ä¸€é\n");	
			
				if(zhaodaoflag == 1)
				{
//				printf("æ‰¾åˆ°äº?");		
	//			printf("laststartï¼?%d\n",laststart);	
//				printf("tï¼?%d\n",to);	
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
    return *(int *)a-*(int *)b;//é‰â•‚ç‘¦å¦²å‘Šç¦’æ´ï¼„æ¯ˆé–¸æŽ“æ¾˜éŠ‡å›¬å¹’éŽºæˆ ç¢é–¿æ¶˜çŸç€šãˆ¤å¼°é¡–æ¬‘çŸ¤å©¢å †å†¨ç…‚éå¿“ç¹‘éå¥¸å¹‹éŽ°å‰çª?return *(int *)b-*(int *)a;
}

int notinex(int j,int *except,int n){
	
	int flag = 1;
	//1éžæ¶–åŠŽéŠ‡æ°­ç¨‰å®¥å‘­æ™™é–ºä½¹å£†ç»®å¶‰æŸŒå®€å‹¬æ¡¨
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
		flag = 1;//1éžæ¶–åŠŽéŠ‡æ°¶å¼µé¡å—™æ³¢é–º?
	} 
	return flag;
}
int iscomeback(int (*newroadcoins)[3],int n,int citys)//néžæ¶˜çž¼å¨ˆæˆžç¨‰æ¾¶å©‚ç™é–ºä½¹å£†ç»?
{
//0éžæ¶–åŠŽéŠ‡æ°¶å¼µé¡å—™æ³¢é–º?1éžæ¶–åŠŽéŠ‡æ°¬î†é‘¼î„‚ç—…ç¼‚ä½¹æŒ»å¨?
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
		
	//é–¸æŽ‹å€–éŒå›©â‚¬æ¶™Ãªå©€îˆå´¶éé›ç®šé–¿?
	
	 huihuanflag=0;//å‡è®¾æ²¡æœ‰å›žçŽ¯ 
	 int start = 0;
	for(ikkkk=0;ikkkk<tempn;ikkkk++)
	{ 
//	startto(int (*newroadcoins)[3],int n,int start,int to);
		if(ikkkk!=start)
		{
//				printf("IKKKK:%d\n",ikkkk);
			 startto(newroadcoins,n,start,ikkkk);
		 	 if(nothuihuanflag == 1)//Èç¹û´Ó0µã×ßµ½ÁíÒ»¸öµã×ßµÃÍ¨ £¬Ôò²âÊÔÏÂÒ»×é×éºÏ 
		 	 						//Èç¹û0µã×ßÍ¨ÁËÈ«²¿£¬ËµÃ÷ÎÞ»Ø»· 
		 	 {
		 	 	nothuihuanflag = 0;
		 	 }
		 	 else//Èç¹û×ß²»Í¨ËµÃ÷´æÔÚ»·Â· 
		 	  {
	//	 	  		printf("\n");
	//	 	  		printf("\n");
//		 	  		printf("MEILUKEYIDAO");
	//	 	  		printf("\n");
		 	 	huihuanflag =1;
		 	 	break;
		 	 	}
		 	 
		}
		
	 
		 //ä¸€æ—¦ä¸€ä¸ªåœ°æ–¹èµ°ä¸åˆ°ï¼Œé‚£å°±gg 
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
	
		if(huihuanflag == 0)//é–ºå†ªå§´å¨²æ ­æ‚³é¡–ã‚‡ç¤‰æ¥ ç‚´æ¹¹ç»?
		{
//					printf("\n");
//		 	  		printf("\n");
//		 	  		printf("huihuanflag==0!!!!");
//		 	  		printf("\n");
			//ç¼‚ä½¹ææ¾¶å‹¯å´¯?
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
	int flag = 1;//1éžæ¶–åŠŽéŠ‡æ­œu é–¸ï¸ºåŠ‘é£çƒ½æ£ƒ?
	for(i=0;i<n;i++)
	{
		if(shuzu[i]==e)
		flag = 0;//0éžæ¶–åŠŽéŠ‡æ°¶å´·éŠŠâ•æ«¡é—‚?
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
	int mincoins = 0;//æ¿®ç‘°å€¸é¤î…¢å¼µéˆ§î„‚äº¸è¹‡æ¶˜æ«¨é¢îˆ™èƒ¶ç»®å¶‰å´¥é«ç†¸æ®¶é–¿æ¶˜çž¼é”Ñ‡å´¥æ´ã„¤æ†¾é–¸?
	int zuheshu = roads-citys+1;
	int newroadcoins[roads][3];//é‰â•‚ç¨‘éªžæ’»å´¶éé›ç®šå©¢è·ºå«®éŽ®å©‡æƒƒé•î„æ®¶ç¼?
	int count=0;
	
	int tempzuheshu = zuheshu;
	
	int shuzu[tempzuheshu];
	for(i=0;i<zuheshu;i++)
	shuzu[i]=0;
	
	while(tempzuheshu--)
	{
	
		 	
		 	
		 while(notend(shuzu,roads-1,zuheshu))//è¤°æ’¶è¢«é¨å¬«æ¹­ç¼æ’´æ½?
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
		 
		 	if(notequl(shuzu,zuheshu))//è¤°æ’²ç¬‰é©å“¥ç“‘éƒèˆµå¢ æ©æ¶˜å† 
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
			//é–¸æŽ‹å€–éŒå›¬å¼°é¡–æ°­å„ŠéŽæ¶™Ãªå©€îˆæ‚³é¡–æ¿ˆç†? 
			iscomeback(newroadcoins,count,citys);
		}
			//éå¿”ç¹†é¦îˆžæŸ†å®¥å‘­å?
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
		int count=0;//é—æ’ç§µéŒå©‡å¹’éŽºæ¥€æ«¨é¢îˆ™ç·šéŠ†åº¢æƒ”è¹‡æ’´å‹¾é–¸ãƒ¦æ‹ç»±æ¿‹å¼³éŒæ¶™î˜§é–»?
		
		for(i=0;i<roads;i++)//é ä¾¯åžµç»»å†®å´šå¦¤å‹©â‚¬å†®å´šå©µå—©æ½—é–?1å¨´ç‹…ç¶€éŠ†å†ªæŒ§éŽ·å²€ç®–å¨´?
			luguo[i]=0;

	for(i=0;i<roads;i++)
	{
		scanf("%d",&roadcoins[i][0]);
		scanf("%d",&roadcoins[i][1]);
		scanf("%d",&roadcoins[i][2]);
	}
	for(i=0;i<roads;i++)//aé–ºä½¹å£†ç»®å¶‰æŸŒå®€å‹¬æ¡¨é–ºâ‚¬éŽ¯Ñƒå¼³é–¹çƒ˜å¸’ç»¨î…Ÿç¸½é£å±¾ç•±roadcoins 
	{
		a[i] = roadcoins[i][2];
	}

	qsort(a,roads,sizeof(a[0]),cmp);//(é–ºä½¹å£†ç»®å¶‰æ•å®€å‹¬ä»˜éŸæ›šç„¦ç”¯æ’´æƒ”è¹‡æ›Ÿç•±é–ºä½¹æ¾˜é¡Ñ„ç¨‰é¡å‘®æ®¶é–¿æ¶˜è‹¯å®•ç†¸ç¨‰é¡å‘®æ®¶éŽæ¶™îš†æ¾§å¶‰å´¡é˜æ’æ•¶éŽæ¶™ÃªéŠ‡å›©äº¸è¹‡ãƒ§ç¤‰æ¿®ï½†æ£ç»¶æ¿‹å´™é‘ºãƒ¦æ®¶é–?
//	for(i=0;i<roads;i++)//aé–ºä½¹å£†ç»®å¶‰æŸŒå®€å‹¬æ¡¨é–ºâ‚¬éŽ¯Ñƒå¼³é–¹çƒ˜å¸’ç»¨î…Ÿç¸½é£å±¾ç•±roadcoins 
//	{
//		printf("a[%d]: %d ",i,a[i]);
//	}
	
	//é–¹ç¨¿î˜µé£å‰§æ•®æµ£é£ŽçŸ¤éå¿“ç¹é©å±¾å¾„è¤”é£æå¼¬é—å ç¬“é¢îˆšå…oadcoins
	 while(count<roads)
	 {
	 	for(i=0;i<roads;i++)//aé–ºä½¹å£†ç»®å¶‰æŸŒå®€å‹¬æ¡¨é–ºâ‚¬éŽ¯Ñƒå¼³é–¹çƒ˜å¸’ç»¨î…Ÿç¸½é£å±¾ç•±roadcoins 
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
	 
	 //éŽç‘°æœ¬é¨æ°­ç¨Šç€£î…å€µé–ºå±»å„³å©€?
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
