#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
	int m;
	cin >> m;
	for (long n = 10000; n < 100000; n++)
	{
		int a = n / 10000;				//��һ��
		int b = (n - a * 10000) / 1000;			//�ڶ���
		int c = (n - a * 10000 - b * 1000) / 100;		//������
		int d = (n - a * 10000 - b * 1000 - c * 100) / 10;	//���ĸ�
		int e = (n - a * 10000 - b * 1000 - c * 100) % 10;	//�����	 
		if (a == e && b == d)	//�Ƿ�Ϊ������ 
		{
			if (a + b + c + d + e == m)	//�Ƿ�Ϊ��λ��������� 
			{
				cout << n << endl;
			}
		}
	}
	for (long n = 100000; n < 1000000; n++)
	{
		int a = n / 100000;					//��һ��
		int b = (n - a * 100000) / 10000;				//�ڶ���
		int c = (n - a * 100000 - b * 10000) / 1000;			//������
		int d = (n - a * 100000 - b * 10000 - c * 1000) / 100;		//���ĸ�
		int e = (n - a * 100000 - b * 10000 - c * 1000 - d * 100) / 10;	//�����	
		int f = (n - a * 100000 - b * 10000 - c * 1000 - d * 100) % 10;	//������
		if (a == f && b == e && c == d)	//�Ƿ�Ϊ������ 
		{
			if ((a + b + c + d + e + f) == m)		//�Ƿ�Ϊ��λ��������� 
			{
				cout << n << endl;
			}
		}
	}
	system("pause");
	return 0;
}