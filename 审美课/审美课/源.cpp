#include<iostream>
#include<stdlib.h>

using namespace std;

int A[50005];
int res[2000000] = { 0 };//m���20λ����˸���������ֵҪ����20��1��Ӧ��ʮ����
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
			A[i] = (A[i] << 1) + tmp; //ע���������ȼ� "+" > "<<" 
		}
		res[A[i]]++;
	}
	int max = (1 << m) - 1;//����ȫ1������
	for (int i = 0; i < n; i++)
	{
		int tmp = A[i] ^ max;//�������а�λȡ��
		ans += res[tmp];
	}
	cout << ans / 2;
	system("pause");
	return 0;
}