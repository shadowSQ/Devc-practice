class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> m;//构建一个字段dictionary 
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(m.count(target-nums[i])&&m[target-nums[i]]!=i)//若target-nums存在 ，并且两者不在同一个位置 
                return {i,m[target-nums[i]]};
        }
        return {};
    }
};
