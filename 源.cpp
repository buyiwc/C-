#include<iostream>  //�ʾ�  
#include<stdlib.h>
#include<math.h>
using namespace std;

int n, m, k, j, c[55][2], y[27][2], d[12], f1, f2, f[55] = { 0 };
float yc[27][55], s = 1000000000;
int dfs(int t, int i, int o[12], float w[55], float sum)
{
	if (i <= m + 1)//�����û�б��������е��ʾ�
	{
		if (t == k)//����Ѿ�ȷ�����ʾ������㹻
		{
			if (sum < s)
			{
				s = sum;//s��������С������ֵ
				for (j = 0; j < k; j++)
					d[j] = o[j];//������o��k��ֵ��������d
			}
		}
		else if (i <= m && t < k)//��û��ȷ�������ʾ���
		{
			float ww[55];
			for (j = 1; j <= n; j++)
				ww[j] = w[j];
			dfs(t, i + 1, o, w, sum); f1 = 1, f2 = 0;//��һ���ʾ֣���ʼ����������õı���f1��f2
			if (!f[i])//f[i]==0,��û�б�����
			{
				o[t] = i;//��t����ȷ���ʾ���i
				if (t > 0)//ww��ʼ���Ѿ�
				{
					f2 = 1;
					for (j = 1; j <= n; j++)
					{
						if (ww[j] > yc[i][j])//����ʾֵ�����ҵľ���С�ڵ�ǰ��С
						{
							sum = sum - ww[j] + yc[i][j];//����
							ww[j] = yc[i][j];
							f1 = 0;//�仯����������ǰ�ʾ�
						}
					}
				}
				else//��û�г�ʼ��
				{
					for (j = 1; j <= n; j++)
					{
						sum += yc[i][j];
						ww[j] = w[j] = yc[i][j];//��ʼ����Сֵ���ǵ�ǰֵ
					}
				}
				if (f1&&f2)//�Ѿ��й�ww��ʼ������Ҫ������ǰ���ʾ֣�ww���δ��ʼ����ôһ�����ܼ���
				{
					f[i] = 1;//���������Ѿ�������
					dfs(t, i + 1, o, w, sum);//��һ�ε���t������
				}
				else
					dfs(t + 1, i + 1, o, ww, sum);//��һ�ε���
			}
		}
	}
}
int main()
{
	int i, j, o[12];
	float w[55], ww[55];
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
		cin >> c[i][0] >> c[i][1];
	for (i = 1; i <= m; i++)
	{
		cin >> y[i][0] >> y[i][1];
		for (j = 1; j <= n; j++)
			yc[i][j] = sqrt((c[j][0] - y[i][0])*(c[j][0] - y[i][0]) + (c[j][1] - y[i][1])*(c[j][1] - y[i][1]));
	}//yc[i][j]�����i���ʾֵ���j������ҵľ���
	dfs(0, 1, o, w, 0);
	for (i = 0; i < k; i++)
		cout << d[i] << " ";
	return 0;
}