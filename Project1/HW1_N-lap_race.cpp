#include <iostream>
using namespace std;

int main()
{
	int t;
	int N, C;
	cin >> t;
	for (int i = 0; i < t; i++) {
		bool result = false;
		cin >> N >> C;
		int index_c = 0; // ������� ä���� car_num ���� 
		int* array = new int[N * C];
		int* car = new int[C]; // car_num�� ù��° ���� ������ ����ϴ� array
		int* block = new int[C]; // car_num�� ���� ������ ����ϴ� array
		for (int j = 0; j < N * C; j++) {
			cin >> array[j];
		}
		for (int j = 0; j < C; j++) {
			block[j] = 0;
			car[j] = 0;
		}
		for (int j = 0; j < N * C; j++) {
			if (j == 0) {
				car[j] = array[j];
				block[j]++;
				index_c++;
			}
			else {
				for (int k = 0; k <= index_c; k++) {
					if (k == index_c) {
						car[k] = array[j];
						block[k]++;
						index_c++;
						break;
					}
					if (car[k] == array[j]) {
						block[k]++;
						if (k != 0) {
							if (block[k] > block[k - 1]) {
								result = true;
							}
						}
					}

				}
			}
		}
		if (result == false) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}