class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> nums2 = nums;	//���Ƹ����� 
		sort(nums);					//������һ������ 
		vector<int> res,res1; //�ٶ�������vector 
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
		//�ӵ�һ������ʼ�����������м������ӣ������Ŀ��С�����м�������ȡһ�� 
		// �����Ŀ������м������ǰȡһ��
		//���ȡ���˶�û�У��򻻵��ڶ�����ִ�д˲��� 
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
			if (!res.empty())//�������˴𰸣�����Ҫ��forѭ�� 
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
void Solution::sort(vector<int> & array) {//�������� 
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
