#include<stdio.h>

//寻找重复子字符串 
//函数：FindSubString 寻找回文字符 ,例如ABCDCBA ，返回顺序字母的个数 
//CSDN、 
//https://www.baidu.com/link?url=4skEIHZwYyf0iTtJOrVUCrSL2_vksFDg-2hhjZetqPxPreSB6KWKm_m
//iej8oh-R2lk2qiIAcscibh9mA3zPyDEJ7WIM2DxIjq7dsDh5XeRfP31RXRq0vpU7VCNpykZp7&wd=&eqid=af272ae80002f5ee000000065ac9fae7

//ModifyString() 函数不断寻找上述类型的子串，如果不满足条件，就
//*p2++ = *p1++; 

//字符串---XYBCDCBABABA 
int FindSubString( char* pch )//字符指针参数 
{
    int   count  = 0;
    char  * p1   = pch;//p1指向字符串首字符 
    while ( *p1 != '\0' )
    {   
        if ( *p1 == p1[1] - 1 ) //如果当前元素等于它后面一个元素的ascii值减一的那个字符的话 
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
        if ( *p1 == p1[1] + 1 ) //如果当前元素等于字它后面一个元素的ascii值加一的那个字符的话 
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
		  // sprintf 重定向修改 ABABA ， B 变为 1 ，
		  //且跟随一个 ‘\0’ （该函数自动产生的） , 此时，字符串变为 A1‘\0’BA 。 
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
