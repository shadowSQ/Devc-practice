class Solution {  
//首尾不相邻的话，
//需要定义一个数组，包含第一个房子的和记录做1.在处理最后一个的时候，如果是1
//不能够加上最后一个
public:  
    int rob(vector<int> &num) {  
        if(num.empty())  
        {  
            return 0;  
        }  
        int res = 0;  
        int length = num.size();  
        if(1 == length)  
        {  
            return num[0];  
        }  
        if(length >= 3)  
        {  
            num[2] = num[0]+num[2];  
        }  
        for(int i = 3; i < length; i++)  
        {  
            if(num[i-2]>num[i-3])  
            {  
                num[i] += num[i-2];  
            }  
            else  
            {  
                num[i] += num[i-3];  
            }  
              
        }  
        return (num[length-2]>num[length-1])? num[length-2]:num[length-1];  
          
    }  
};  