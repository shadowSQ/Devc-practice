#include<stdio.h>

//Ѱ���ظ����ַ��� 
//������FindSubString Ѱ�һ����ַ� ,����ABCDCBA ������˳����ĸ�ĸ��� 
//CSDN�� 
//https://www.baidu.com/link?url=4skEIHZwYyf0iTtJOrVUCrSL2_vksFDg-2hhjZetqPxPreSB6KWKm_m
//iej8oh-R2lk2qiIAcscibh9mA3zPyDEJ7WIM2DxIjq7dsDh5XeRfP31RXRq0vpU7VCNpykZp7&wd=&eqid=af272ae80002f5ee000000065ac9fae7

//ModifyString() ��������Ѱ���������͵��Ӵ��������������������
//*p2++ = *p1++; 

//�ַ���---XYBCDCBABABA 
int FindSubString( char* pch )//�ַ�ָ����� 
{
    int   count  = 0;
    char  * p1   = pch;//p1ָ���ַ������ַ� 
    while ( *p1 != '\0' )
    {   
        if ( *p1 == p1[1] - 1 ) //�����ǰԪ�ص���������һ��Ԫ�ص�asciiֵ��һ���Ǹ��ַ��Ļ� 
        {
            p1++;
            count++;
        }else  {
            break;
        }
    }
    int count2 = count;
    while ( *p1 != '\0' )
    {
        if ( *p1 == p1[1] + 1 ) //�����ǰԪ�ص�����������һ��Ԫ�ص�asciiֵ��һ���Ǹ��ַ��Ļ� 
        {
            p1++;
            count2--;
        }else  {
            break;
        }
    }
    if ( count2 == 0 )
        return(count);
    return(0);
}


void ModifyString( char* pText )
{
    char  * p1   = pText;
    char  * p2   = p1;
    while ( *p1 != '\0' )
    {
        int count = FindSubString( p1 );
     //    printf( "%d", count);
        if ( count > 0 )
        {
            *p2++ = *p1;
          sprintf( p2,"%i", count );
		  // sprintf �ض����޸� ABABA �� B ��Ϊ 1 ��
		  //�Ҹ���һ�� ��\0�� ���ú����Զ������ģ� , ��ʱ���ַ�����Ϊ A1��\0��BA �� 
            while ( *p2 != '\0' )
            {
                p2++;
            }
            p1 += count + count + 1;
        }else  {
            *p2++ = *p1++;
        }
    }
}

int main(void)
{
    char text[32] = "XYBCDCBABABA";
    ModifyString( text );
    printf( text );
    
}  
