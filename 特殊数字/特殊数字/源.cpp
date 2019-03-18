#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main()
{
	int i;
	for (i = 100; i < 1000; i++)
	{
		int a = i / 100;
		int b = (i - a * 100) / 10;
		int c = (i - a * 100) % 10;
		if (i == a * a*a + b * b*b + c * c*c)
			cout << i << endl;
	}
	system("pause");
	return 0;
}