#include <stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
/*  在H.264视频编码标准中，编码帧由NALU头和NALU主体组成，
其中NALU头由一个字节组成。在实际编码时，
在每个NAL前添加起始码 0x000001，解码器在码流中检测到起始码，
当前NAL结束。为了防止NAL内部出现0x000001的数据，在编码完一个NAL时，如果检测出有连续两个0x00字节，就在后面插入一个0x03。
当解码器在NAL内部检测到0x000003的数据，就把0x03抛弃，恢复原始数据。
给定一组包含SPS NALU的编码数据，找出解码后的SPS数据。比如：
输入：{0x1f 0x00 0x00 0x01 0x67 0x42 0xd0 0x80
 0x00 0x00 0x03 0x00 0x80 0x00 0x0f 0x00 0x00 
 0x01 0x68 0xce 0x3c 0x80},
处理：在上述例子中，
第一个0x00 0x00 0x01为识别到的数据头，
0x00 0x00 0x03 0x00数据中，0x03为需抛弃数据，
第二个0x00 0x00 0x01为下一个数据头，
那么取出两个数据头中间的数据并且抛弃掉此0x03，结果如下：
{0x67 0x42 0xd0 0x80 0x00 0x00 0x00 0x80 0x00 0x0f }。  
int find_sps_in_h264(unsigned char[],int N)
input:
1
23
0 0 01 67 42 c0 16 d0 80 0 0 03 0 80 0 0f 0 0 01 68 ce 3c 80
output:
67 42 c0 16 d0 80 0 0 0 80 0 0f */
void find_max_sum_without_adjacents(string *mima,int N)
{
	int i,kk;	
	int count = 0;
	int se[100] = {0};
	int tempse[100] = {0};

	
	for(i=0;i<N-2;i++)//遍历 
	{
		if(mima[i]=="00"||mima[i]=="0") 
		{
			if(mima[i+1]=="00"||mima[i+1]=="0")
			{
			
			if(mima[i+2]=="01"||mima[i+2]=="1")
			{
				se[count] = i+1;
			tempse[count]= i+1;
			count++;
			}	
			} 
	
		}
	}

	for(kk=0;kk<count-1;kk++)
	{
			for(i=se[kk]+2;i<se[kk+1]-1;i++)//遍历 
		{
			
			if(mima[i]=="00"||mima[i]=="0") 
		{
				if(mima[i+1]=="00"||mima[i+1]=="0")
			{
			
			if(mima[i+2]=="03"||mima[i+2]=="3")
			{
				int j=i+2;//j来遍历 
				for(;j<se[kk+1]-1;j++)//遍历 
				{
					mima[j]=mima[j+1];		
				}
				tempse[kk+1]-=1; 
			}	
			} 
	
		}
		
		}
		
		for(i=se[kk]+2;i<tempse[kk+1]-1;i++)//遍历 
		{
			if(mima[i]=="0")
			cout<<"00 ";
			else
		cout<<mima[i]<<" ";
		}
	}

	
	
}

int main(){
	int T;
	int i,N;
	scanf("%d",&T);

	while(T--)
	{
		
	scanf("%d",&N);
	string mima[N]; 
	for(i=0;i<N;i++)
	{
	cin>>mima[i];
	}

	find_max_sum_without_adjacents(mima,N);
	}

return 0;

}
