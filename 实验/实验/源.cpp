#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
#define pi 3.1415926

double max1(double, double, double c = 0);
int main()
{
	int i = 1, sum = 0, n, c, k;
	double s, r;
	cout << "输入图形类型：1（圆形），2（正方形），3（长方形）,4(do while),5(for)" << endl;
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "输入半径" << endl;
		cin >> r;
		s = pi * r*r;
		cout << s << endl;
		//break;
	case 2:
		cout << "输入边长" << endl;
		cin >> c;
		s = c * c;
		cout << s << endl;
		//break;
	case 3:
		cout << "输入长、宽" << endl;
		cin >> c >> k;
		s = c * k;
		cout << s << endl;
		//break;
	case 4:
		do
		{
			sum += i;
			i++;
		} while (i <= 10);
		cout <<"和为："<< sum << endl;
		//break;
	case 5:
		sum = 0;
		for (i = 1; i <= 10; i++)
		{
			sum += i;
		}
		cout <<"和为："<< sum << endl;
		break;
	}


	system("pause");
	return 0;
}

