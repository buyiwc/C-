#include<iostream>
#include<stdlib.h>

using namespace std;

int A[50005];
int res[2000000] = { 0 };//m最多20位，因此该数组的最大值要包括20个1对应的十进制
int ans = 0;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int tmp;
			cin >> tmp;
			A[i] = (A[i] << 1) + tmp; //注意运算优先级 "+" > "<<" 
		}
		res[A[i]]++;
	}
	int max = (1 << m) - 1;//构造全1二进制
	for (int i = 0; i < n; i++)
	{
		int tmp = A[i] ^ max;//用异或进行按位取反
		ans += res[tmp];
	}
	cout << ans / 2;
	system("pause");
	return 0;
}