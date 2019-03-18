#include<iostream>
using namespace std;
#include<stdlib.h>

int main()
{
	long long n, number;
	cin >> n;
	if (n <= 2)
	{
		cout << 2;
	}
	else if (n % 2)
	{
		number = n * (n - 1) * (n - 2);
		cout << number<<endl;
	}
	else
	{
		if (n % 3 == 0)
		{
			number = (n - 1) * (n - 2) * (n - 3);
		}
		else number = n * (n - 1) * (n - 3);
		cout << number<<endl;
	}
	system("pause");
	return 0;
}