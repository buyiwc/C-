#include<iostream>
using namespace std;
int main()
{
	int y,n,a[1000],pos=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> y;
	for (int i = 1; i <= n; i++)
	{
		if (i > n)
			cout << -1 << endl;
		else if (a[i] == y) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}