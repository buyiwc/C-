#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include<stdlib.h>
using namespace std;
int n, m;
int f(int x, int y)  //��ʾA��ʣx����B��ʣy��
{
	if (y == 0 || x == 0) //���A����Bû���ˣ���������ȷ����
		return 1;
	if (n - x == m - y)  //����Ѿ�ȡ��A�ĸ�����B�ĸ�����ͬ����һ���϶�ҪȡA
		return f(x - 1, y);
	else if (n - x > m - y) //����Ѿ�ȥ��A�ĸ�����B����ô����ν����һ��ҪôȡA��ҪôȡB
		return f(x - 1, y) + f(x, y - 1);
	return 0;
}
int main()
{
	scanf_s("%d%d", &n, &m);
	if (n < m)     //���û���⣬��һ��û����һ��Ҫ�Ͻ�
		printf_s("0\n");
	else
		printf_s("%d\n", f(n, m));
	system("pause");
	return 0;
}