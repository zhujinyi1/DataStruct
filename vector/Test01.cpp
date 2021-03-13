#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//const int N = 200;
int main()
{
	vector<int> a;
	vector<int> b;
	vector<int> c;
	cout << "请输入数组大小n：" << endl;
	int n,m;
	cin >> n;
	cout << "请输入数组中的每一个数:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		a.push_back(m);
	}
	for (int j = n; j >0; j--)
	{
		if ((a.back()) % 2 == 0)
			b.push_back(a.back());
		else
			c.push_back(a.back());
		a.pop_back();
	}
	
	for (int k = c.size(); k > 0; k--)
	{
		b.push_back(c.back());
		c.pop_back();
	}
	cout << b.front() << endl;
	cout << "调整后的数组顺序：" << endl;
	while(b.size()!=0)
	{
		cout << b.back() << " ";
		b.pop_back();
	}
}

