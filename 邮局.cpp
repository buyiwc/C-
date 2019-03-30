#include<iostream>  //邮局  
#include<stdlib.h>
#include<math.h>
using namespace std;

int n, m, k, j, c[55][2], y[27][2], d[12], f1, f2, f[55] = { 0 };
float yc[27][55], s = 1000000000;
int dfs(int t, int i, int o[12], float w[55], float sum)
{
	if (i <= m + 1)//如果还没有遍历完所有的邮局
	{
		if (t == k)//如果已经确定的邮局数已足够
		{
			if (sum < s)
			{
				s = sum;//s是最后的最小距离总值
				for (j = 0; j < k; j++)
					d[j] = o[j];//将数组o的k个值存入数组d
			}
		}
		else if (i <= m && t < k)//还没有确定所有邮局数
		{
			float ww[55];
			for (j = 1; j <= n; j++)
				ww[j] = w[j];
			dfs(t, i + 1, o, w, sum); f1 = 1, f2 = 0;//下一个邮局，初始化两个标记用的变量f1，f2
			if (!f[i])//f[i]==0,还没有被剪掉
			{
				o[t] = i;//第t个已确定邮局是i
				if (t > 0)//ww初始化已经
				{
					f2 = 1;
					for (j = 1; j <= n; j++)
					{
						if (ww[j] > yc[i][j])//如果邮局到村民家的距离小于当前最小
						{
							sum = sum - ww[j] + yc[i][j];//更新
							ww[j] = yc[i][j];
							f1 = 0;//变化，不剪掉当前邮局
						}
					}
				}
				else//还没有初始化
				{
					for (j = 1; j <= n; j++)
					{
						sum += yc[i][j];
						ww[j] = w[j] = yc[i][j];//初始化最小值就是当前值
					}
				}
				if (f1&&f2)//已经有过ww初始化且需要剪掉当前的邮局，ww如果未初始化那么一定不能剪掉
				{
					f[i] = 1;//经过处理，已经被剪掉
					dfs(t, i + 1, o, w, sum);//下一次迭代t不增加
				}
				else
					dfs(t + 1, i + 1, o, ww, sum);//下一次迭代
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
	}//yc[i][j]代表第i个邮局到第j个村民家的距离
	dfs(0, 1, o, w, 0);
	for (i = 0; i < k; i++)
		cout << d[i] << " ";
	return 0;
}