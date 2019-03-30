#include<iostream>
using namespace std;

int Actm(int s[20], int f[20], bool a[20],int n)
{
	a[1] = 1;
	int j = 1;
	int count = 1;
	cout << "加入安排的活动有：" << 1 << " ";
	for (int i = 2; i <= n; i++)
	{
		if (s[i] > f[j])
		{
			a[i] = 1;
			j = i;
			count++;
			cout <<j<<" ";
		}
		
		else
			a[i] = 0;
		
	}
	cout << endl;
	return count;
}

int main()
{
	int n;
	
	cout << "输入活动个数" << endl;
	cin >> n;
	int s[20];
	int f[20];
	bool a[20] = { 0 };
	cout << "输入活动开始时间" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	cout << "输入活动结束时间" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> f[i];
	}
	int k=Actm(s, f, a, n);
	cout << "加入活动个数为" << k << endl;
	return 0;
}