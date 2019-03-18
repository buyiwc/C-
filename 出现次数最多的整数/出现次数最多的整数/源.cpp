#include <iostream>
#include<cstdlib>
using namespace std;
#define N 50

//打印盒子 
void print(int n, int game[][N]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << game[i][j] << " ";
		}

		cout << endl;
	}

}


//递归函数 
void arrange(int p, int q, int t, int arr[][N]) {


	//规格为4及以上，它的左上角和右上角要递归
	if (t >= 4) {
		arrange(p, q, t / 2, arr);
		arrange(p, q + t / 2, t / 2, arr);
	}

	//填左下角
	for (int i = p + t / 2; i < p + t; i++) {
		for (int j = q; j < q + t / 2; j++) {
			arr[i][j] = arr[i - t / 2][j + t / 2];
		}
	}
	//填右下角 
	for (int i = p + t / 2; i < p + t; i++) {
		for (int j = q + t / 2; j < q + t; j++) {
			arr[i][j] = arr[i - t / 2][j - t / 2];
		}
	}


}


//主函数
int main() {
	int n;
	int game[N][N];

	cout << "请输入选手人数:" << endl;
	cin >> n;

	//初始化第一行,其他全为0 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0)
				game[i][j] = j + 1;
			else
				game[i][j] = 0;
		}
	}


	//递归 
	arrange(0, 0, n, game);

	//打印输出循环赛日程表 
	print(n, game);


	system("pause");
	return 0;
}