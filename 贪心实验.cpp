#include<iostream>
using namespace std;

int Actm(int s[20], int f[20], bool a[20],int n)
{
	a[1] = 1;
	int j = 1;
	int count = 1;
	cout << "���밲�ŵĻ�У�" << 1 << " ";
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
	
	cout << "��������" << endl;
	cin >> n;
	int s[20];
	int f[20];
	bool a[20] = { 0 };
	cout << "������ʼʱ��" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	cout << "��������ʱ��" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> f[i];
	}
	int k=Actm(s, f, a, n);
	cout << "��������Ϊ" << k << endl;
	return 0;
}