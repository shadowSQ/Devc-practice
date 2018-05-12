class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> nums2 = nums;	//复制该数组 
		sort(nums);					//对其中一份排序 
		vector<int> res,res1; //再定义两个vector 
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
		//从第一个数开始和排序后的最中间的数相加，如果比目标小，则中间的数向后取一个 
		// 如果比目标大，则中间的数向前取一个
		//如果取完了都没有，则换到第二个数执行此操作 
			int end = n - 1, start = i + 1;
			int j = (end + start) / 2;

			while (j <= end&&j >= start) {
				if (nums[i] + nums[j]>target) {
					end = j - 1;
					j = (end + start) / 2;

				}
				else if (nums[i] + nums[j]<target) {
					start = j + 1;
					j = (end + start) / 2;
				}
				else {
					res.push_back(nums[i]);
					res.push_back(nums[j]);
					break;
				}
				
			}
			if (!res.empty())//如果求出了答案，不必要再for循环 
				break;
			
		}//for 
		int nu = 0;
		for (int i = 0; i < n; ++i) {
			if (nums2[i] == res[0]) {
				res1.push_back(i);
				++nu;
                
			}
			else if (nums2[i] == res[1])
			{
				res1.push_back(i);
				++nu;
                
			}
			if (nu >= 2)
				break;
		}//for
		//cout << res1[0] << " " << res1[1];
		return res1;

	}
	void sort(vector<int> & iv);
};
void Solution::sort(vector<int> & array) {//快速排序 
	int lenth = array.size();
	int temp = 0;
	int incre = lenth;

	while (true) {
		incre = incre / 2;

		for (int k = 0; k<incre; k++) {

			for (int i = k + incre; i<lenth; i += incre) {

				for (int j = i; j>k; j -= incre) {
					if (array[j]<array[j - incre]) {
						temp = array[j - incre];
						array[j - incre] = array[j];
						array[j] = temp;
					}
					else {
						break;
					}
				}
			}
		}

		if (incre == 1) {
			break;
		}
	}
}
