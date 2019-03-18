#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
int b[10], c[10];
char a[10][100000];//输入的几个十六进制数 
int d[10][400000] = { 0 }; //十六进制转换为二进制BCD后的数 
int e[10][133334]; //BCD转换为八进制后的数 
int main(void)
{
	int i, j, k, n;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%s", a[i]);
		b[i] = strlen(a[i]);  //代表每个字符串的长度 
		c[i] = b[i] * 4;//表示每个字符串转换成二进制的长度 
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < b[i]; j++)
		{
			switch (a[i][j])
			{
			case '0':
			{
				d[i][j * 4 + 0] = 0;
				d[i][j * 4 + 1] = 0;
				d[i][j * 4 + 2] = 0;
				d[i][j * 4 + 3] = 0;
				break;
			}
			case '1':
			{
				d[i][j * 4 + 0] = 0;
				d[i][j * 4 + 1] = 0;
				d[i][j * 4 + 2] = 0;
				d[i][j * 4 + 3] = 1;
				break;
			}
			case '2':
			{
				d[i][j * 4 + 0] = 0;
				d[i][j * 4 + 1] = 0;
				d[i][j * 4 + 2] = 1;
				d[i][j * 4 + 3] = 0;
				break;
			}
			case '3':
			{
				d[i][j * 4 + 0] = 0;
				d[i][j * 4 + 1] = 0;
				d[i][j * 4 + 2] = 1;
				d[i][j * 4 + 3] = 1;
				break;
			}
			case '4':
			{
				d[i][j * 4 + 0] = 0;
				d[i][j * 4 + 1] = 1;
				d[i][j * 4 + 2] = 0;
				d[i][j * 4 + 3] = 0;
				break;
			}
			case '5':
			{
				d[i][j * 4 + 0] = 0;
				d[i][j * 4 + 1] = 1;
				d[i][j * 4 + 2] = 0;
				d[i][j * 4 + 3] = 1;
				break;
			}
			case '6':
			{
				d[i][j * 4 + 0] = 0;
				d[i][j * 4 + 1] = 1;
				d[i][j * 4 + 2] = 1;
				d[i][j * 4 + 3] = 0;
				break;
			}
			case '7':
			{
				d[i][j * 4 + 0] = 0;
				d[i][j * 4 + 1] = 1;
				d[i][j * 4 + 2] = 1;
				d[i][j * 4 + 3] = 1;
				break;
			}
			case '8':
			{
				d[i][j * 4 + 0] = 1;
				d[i][j * 4 + 1] = 0;
				d[i][j * 4 + 2] = 0;
				d[i][j * 4 + 3] = 0;
				break;
			}
			case '9':
			{
				d[i][j * 4 + 0] = 1;
				d[i][j * 4 + 1] = 0;
				d[i][j * 4 + 2] = 0;
				d[i][j * 4 + 3] = 1;
				break;
			}
			case 'A':
			{
				d[i][j * 4 + 0] = 1;
				d[i][j * 4 + 1] = 0;
				d[i][j * 4 + 2] = 1;
				d[i][j * 4 + 3] = 0;
				break;
			}
			case 'B':
			{
				d[i][j * 4 + 0] = 1;
				d[i][j * 4 + 1] = 0;
				d[i][j * 4 + 2] = 1;
				d[i][j * 4 + 3] = 1;
				break;
			}
			case 'C':
			{
				d[i][j * 4 + 0] = 1;
				d[i][j * 4 + 1] = 1;
				d[i][j * 4 + 2] = 0;
				d[i][j * 4 + 3] = 0;
				break;
			}
			case 'D':
			{
				d[i][j * 4 + 0] = 1;
				d[i][j * 4 + 1] = 1;
				d[i][j * 4 + 2] = 0;
				d[i][j * 4 + 3] = 1;
				break;
			}
			case 'E':
			{
				d[i][j * 4 + 0] = 1;
				d[i][j * 4 + 1] = 1;
				d[i][j * 4 + 2] = 1;
				d[i][j * 4 + 3] = 0;
				break;
			}
			case 'F':
			{
				d[i][j * 4 + 0] = 1;
				d[i][j * 4 + 1] = 1;
				d[i][j * 4 + 2] = 1;
				d[i][j * 4 + 3] = 1;
				break;
			}
			}

		}
	}

	for (i = 0; i < n; i++)
	{
		if (c[i] % 3 == 0)
		{
			for (j = 0; j < c[i] / 3; j++)
			{
				e[i][j] = d[i][j * 3 + 0] * pow(2, 2) + d[i][j * 3 + 1] * pow(2, 1) + d[i][j * 3 + 2] * pow(2, 0);
				if (j != 0 || e[i][j] != 0)
					printf("%d", e[i][j]);
			}
		}
		if (c[i] % 3 == 1)  //需要补两个 
		{
			e[i][0] = d[i][0] * pow(2, 0);
			if (e[i][0] != 0)
				printf("%d", e[i][0]);
			for (j = 0; j < c[i] / 3; j++)
			{
				e[i][j + 1] = d[i][j * 3 + 1] * pow(2, 2) + d[i][j * 3 + 2] * pow(2, 1) + d[i][j * 3 + 3] * pow(2, 0);
				printf("%d", e[i][j + 1]);
			}
		}
		if (c[i] % 3 == 2)
		{
			e[i][0] = d[i][0] * pow(2, 1) + d[i][1] * pow(2, 0);
			if (e[i][0] != 0)
				printf("%d", e[i][0]);
			for (j = 0; j < c[i] / 3; j++)
			{
				e[i][j + 1] = d[i][j * 3 + 2] * pow(2, 2) + d[i][j * 3 + 3] * pow(2, 1) + d[i][j * 3 + 4] * pow(2, 0);
				printf("%d", e[i][j + 1]);
			}
		}
		printf("\n");
	}
	system ("pause");
	return 0;

}