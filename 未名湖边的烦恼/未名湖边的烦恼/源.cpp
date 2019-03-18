#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include<stdlib.h>
using namespace std;
int n, m;
int f(int x, int y)  //表示A还剩x个，B还剩y个
{
	if (y == 0 || x == 0) //如果A或者B没有了，方案数就确定了
		return 1;
	if (n - x == m - y)  //如果已经取的A的个数和B的个数相同，下一个肯定要取A
		return f(x - 1, y);
	else if (n - x > m - y) //如果已经去的A的个数比B大，那么无所谓，下一个要么取A，要么取B
		return f(x - 1, y) + f(x, y - 1);
	return 0;
}
int main()
{
	scanf_s("%d%d", &n, &m);
	if (n < m)     //这个没在意，第一遍没过，一定要严谨
		printf_s("0\n");
	else
		printf_s("%d\n", f(n, m));
	system("pause");
	return 0;
}