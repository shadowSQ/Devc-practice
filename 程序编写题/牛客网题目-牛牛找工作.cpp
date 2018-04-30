#include <iostream>
#include <algorithm>
/*Ϊ���ҵ��Լ�����Ĺ�����ţţ�ռ���ÿ�ֹ������ѶȺͱ��ꡣţţѡ�����ı�׼�����ѶȲ�������������ֵ������£�ţţѡ�񱨳���ߵĹ�����
��ţţѡ�����Լ��Ĺ�����ţţ��С���������ţţ��æѡ������ţţ��Ȼʹ���Լ��ı�׼������С����ǡ�ţţ��С���̫���ˣ�������ֻ�ð�������񽻸����㡣 
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а����������������ֱ��ʾ����������N(N<=100000)��С��������M(M<=100000)��
��������N��ÿ�а����������������ֱ��ʾ��������Ѷ�Di(Di<=1000000000)�ͱ���Pi(Pi<=1000000000)��
��������һ�а���M�����������ֱ��ʾM��С��������ֵAi(Ai<=1000000000)��
��֤������������ı�����ͬ��


�������:
����ÿ��С��飬�ڵ�����һ�����һ����������ʾ���ܵõ�����߱��ꡣһ���������Ա������ѡ��
*/ 
using namespace std;
struct Work { int d, p; };    //�����Ѷ�=d ������=p 
struct People{ int a, index, money; };  // ����ֵ=a�� ���� money 
bool cmp1(Work a, Work b) {   //�Ƚ�����1 ����a���Ѷ��Ƿ�С�ڹ���b 
	return a.d < b.d; 
}
bool cmp2(People a, People b) {  //�Ƚ�����2 ��Աa������ֵ�Ƿ�С����Աb 
	return a.a < b.a;
}
bool cmp3(People a, People b) {
	return a.index < b.index;
}
int main()
{
	int n, m; cin >> n >> m;  //���빤������������ 
	Work *work = new Work[n]; //����һ��workָ�� 
	for (int i = 0; i < n; i++) {
	cin >> work[i].d >> work[i].p; //���빤���ѶȺͱ��� 
	}
People *people = new People[m];
	for (int i = 0; i < m; i++)
	 {
		cin >> people[i].a;	//����С��������ֵ 
		people[i].index = i;//�������� 
	}
	sort(work, work + n, cmp1);  //sort�������������Ѷ�ֵ��С�������� 
	sort(people, people + m, cmp2);//sort���������������ֵ��С�������� 
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
