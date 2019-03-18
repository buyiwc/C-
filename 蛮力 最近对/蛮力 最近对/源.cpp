#include<iostream>
#include <cstdlib>
#include <time.h>
#include<cmath>
using namespace std;
#define N 100000000

struct {

	int x, y;

}zuobiao[N];
double closepoints()

{
	int i;int n;
	cout << "输入生成随机数个数" << endl;
	cin >> n;
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++) {

		zuobiao[i].x = rand() % 10 + 1;

		zuobiao[i].y = rand() % 10 + 1;

		cout << "(" << zuobiao[i].x <<","<< zuobiao[i].y << ")" << endl;

	}
	
	double mind = +N;
	double dis = 0;
	int ind1 = 0; int ind2 = 0;
	for(int i=0;i<n-2;i++)
		for (int j = i + 1; j <= n - 1; j++)
		{
			dis = (zuobiao[i].x - zuobiao[j].x)*(zuobiao[i].x - zuobiao[j].x) + (zuobiao[i].y - zuobiao[j].y)*(zuobiao[i].y - zuobiao[j].y);
			if (dis < mind)
			{
				mind = dis; ind1 = i; ind2 = j;
			}
		}
	cout << "最近点对为第：" << ind1+1 << "," << ind2+1 << "个" << endl;
	return sqrt(mind);
}
int main()
{
	double d;
	d = closepoints();
	cout <<"最近距离为："<< d << endl;
	system("pause");
	return 0;
}