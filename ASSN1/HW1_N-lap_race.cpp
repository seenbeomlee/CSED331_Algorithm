#include<iostream>
using namespace std;
#define size 1000000

int main() {
	int t, N, C, temp, index, result;
	//int car[10000];
	//int block[10000];
	cin >> t;

	for (int i = 0; i < t; i++) { // ���� 0�� -> 1�� -> 2�� ..
		index = 0;
		result = 0;
		cin >> N >> C;

		//for (int j = 0; j < 10000; j++) block[j] = 0;
		//for (int j = 0; j < 10000; j++) car[j] = -1;
		int* car = new int[size];
		int* block = new int[size];
		for (int j = 0; j < size; j++) block[j] = 0;
		for (int j = 0; j < size; j++) car[j] = -1;

		for (int j = 0; j < N * C; j++) {
			cin >> temp;

			if (car[temp - 1] == -1) { // ó�� ���� ��
				car[temp - 1] = index;
				block[car[temp - 1]]++;
				index++;
			}
			else { // 2���� �̻� ���� ��
				block[car[temp - 1]]++;

				if (car[temp - 1] != 0) { // 0���� -1��� ���Ҽ� �����Ƿ� ����
					if (block[car[temp - 1]] > block[car[temp - 1] - 1]) { // �߿��Ѱ��
						result = 1;
						for (int k = j + 1; k < N * C; k++) cin >> temp; // �� �̻� ����� �ʿ䰡 �����Ƿ� ���� �Է°� �����ֱ�
						break;
					}
					else {// �߿��������� 
						continue;
					}
				}
			}
		}

		if (result == 1) cout << "YES" << endl;
		else if (result == 0) cout << "NO" << endl;
		//delete[] car;
		//delete[] block;
	}
	return 0;
}