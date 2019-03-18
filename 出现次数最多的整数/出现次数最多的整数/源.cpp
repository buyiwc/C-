#include <iostream>
#include<cstdlib>
using namespace std;
#define N 50

//��ӡ���� 
void print(int n, int game[][N]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << game[i][j] << " ";
		}

		cout << endl;
	}

}


//�ݹ麯�� 
void arrange(int p, int q, int t, int arr[][N]) {


	//���Ϊ4�����ϣ��������ϽǺ����Ͻ�Ҫ�ݹ�
	if (t >= 4) {
		arrange(p, q, t / 2, arr);
		arrange(p, q + t / 2, t / 2, arr);
	}

	//�����½�
	for (int i = p + t / 2; i < p + t; i++) {
		for (int j = q; j < q + t / 2; j++) {
			arr[i][j] = arr[i - t / 2][j + t / 2];
		}
	}
	//�����½� 
	for (int i = p + t / 2; i < p + t; i++) {
		for (int j = q + t / 2; j < q + t; j++) {
			arr[i][j] = arr[i - t / 2][j - t / 2];
		}
	}


}


//������
int main() {
	int n;
	int game[N][N];

	cout << "������ѡ������:" << endl;
	cin >> n;

	//��ʼ����һ��,����ȫΪ0 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0)
				game[i][j] = j + 1;
			else
				game[i][j] = 0;
		}
	}


	//�ݹ� 
	arrange(0, 0, n, game);

	//��ӡ���ѭ�����ճ̱� 
	print(n, game);


	system("pause");
	return 0;
}