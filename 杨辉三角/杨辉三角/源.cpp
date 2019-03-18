#include<iostream>
#include<stdlib.h>
using namespace std;
int a[35][35];

void yang(int);

int main()
{
	int n;
	cin >> n;
	yang(n);
	system("pause");
	return 0;
}

void yang(int n)
{
	for (int i = 1; i <= 34; i++)
		a[i][1] = a[i][i] = 1;
	for (int i = 3; i < 35; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (int i=1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << a[i][j] << " ";
			
		}
		cout << endl;
	}
};