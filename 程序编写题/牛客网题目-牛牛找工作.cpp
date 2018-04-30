#include <iostream>
#include <algorithm>
/*为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。
在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。 
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
保证不存在两项工作的报酬相同。


输出描述:
对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。
*/ 
using namespace std;
struct Work { int d, p; };    //工作难度=d ，报酬=p 
struct People{ int a, index, money; };  // 能力值=a， 报酬 money 
bool cmp1(Work a, Work b) {   //比较类型1 工作a的难度是否小于工作b 
	return a.d < b.d; 
}
bool cmp2(People a, People b) {  //比较类型2 人员a的能力值是否小于人员b 
	return a.a < b.a;
}
bool cmp3(People a, People b) {
	return a.index < b.index;
}
int main()
{
	int n, m; cin >> n >> m;  //输入工作数量和人数 
	Work *work = new Work[n]; //定义一个work指针 
	for (int i = 0; i < n; i++) {
	cin >> work[i].d >> work[i].p; //输入工作难度和报酬 
	}
People *people = new People[m];
	for (int i = 0; i < m; i++)
	 {
		cin >> people[i].a;	//输入小伙伴的能力值 
		people[i].index = i;//创建索引 
	}
	sort(work, work + n, cmp1);  //sort函数将工作的难度值从小到大排列 
	sort(people, people + m, cmp2);//sort函数将人物的能力值从小到大排列 
	int j = 0, maxMoney = 0;
	for (int i = 0; i < m; i++)
	 {
	while (j < n) {
		if (work[j].d > people[i].a)
		 {
		continue;
		}
			maxMoney = max(maxMoney, work[j].p);
			j++;
		}
				people[i].money = maxMoney;
		}
	sort(people, people + m, cmp3);
	for (int i = 0; i < m; i++) {
		cout << people[i].money << endl;
		}
	delete[] work;
	delete[] people;
	return 0;
}
