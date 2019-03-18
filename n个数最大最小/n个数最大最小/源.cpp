#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define N 10000
void max_min(int, int b[]);
void sum(int a,int b[]);

int main()
{
	int a, b[N];
	scanf_s("%d",&a);
	for (int i = 0; i < a; i++)
		scanf_s("%d",&b[i]);
	max_min(a,b);
	sum(a,b);
	system("pause");
	return 0;
}
void max_min(int a, int b[])
{
	int i,max,min;
	for (i = 0; i + 1 < a; i++)
	{
		min = max = b[0];
		if (b[i + 1] > b[i])
			max = b[i + 1];
		if (b[i + 1] < b[i])
			min = b[i + 1];
	}
	cout << max << "\n" << min << endl;
}

void sum(int a,int b[])
{
	int sum = 0;
	for (int i = 0; i + 1 < a; i++)
		sum = b[i] + b[i + 1];
	cout << sum << endl;
}