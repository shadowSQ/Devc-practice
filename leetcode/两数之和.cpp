class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int>	answer;
        int i=0,j=0,N=nums.size();
        sort(nums.begin(),nums.end());
        
        for(i=0;i<N;i++)
       	{
       		for(j=i+1;j<N;j++)
       		{
       			if(nums[i]+nums[j]==target)
       			{
       				nswer.push_back(num[i]);
        			answer.push_back(num[j]);
        			return answer;
       				
       			}
       		}
       	}
        
        
        
    /*    if(nums[0]>0||nums[N]<0) //如果全部都是正数或者负数 
        {
        	for(i=0;i<N;i++)
       		{
        		if(target==num[i]+nums[i+1])
        		{
        			answer.push_back(num[i]);
        			answer.push_back(num[i+1]);
        			return answer;
        		}
        				
       		}
        }
        else//如果出现一正一负相加才等于target的情况 
        {
        	
        }
        
       */ 
    }
};
