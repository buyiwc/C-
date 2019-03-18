#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
	int m;
	cin >> m;
	for (long n = 10000; n < 100000; n++)
	{
		int a = n / 10000;				//第一个
		int b = (n - a * 10000) / 1000;			//第二个
		int c = (n - a * 10000 - b * 1000) / 100;		//第三个
		int d = (n - a * 10000 - b * 1000 - c * 100) / 10;	//第四个
		int e = (n - a * 10000 - b * 1000 - c * 100) % 10;	//第五个	 
		if (a == e && b == d)	//是否为回文数 
		{
			if (a + b + c + d + e == m)	//是否为五位特殊回文数 
			{
				cout << n << endl;
			}
		}
	}
	for (long n = 100000; n < 1000000; n++)
	{
		int a = n / 100000;					//第一个
		int b = (n - a * 100000) / 10000;				//第二个
		int c = (n - a * 100000 - b * 10000) / 1000;			//第三个
		int d = (n - a * 100000 - b * 10000 - c * 1000) / 100;		//第四个
		int e = (n - a * 100000 - b * 10000 - c * 1000 - d * 100) / 10;	//第五个	
		int f = (n - a * 100000 - b * 10000 - c * 1000 - d * 100) % 10;	//第六个
		if (a == f && b == e && c == d)	//是否为回文数 
		{
			if ((a + b + c + d + e + f) == m)		//是否为六位特殊回文数 
			{
				cout << n << endl;
			}
		}
	}
	system("pause");
	return 0;
}