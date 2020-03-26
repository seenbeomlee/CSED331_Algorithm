#include <iostream>
using namespace std;

int main()
{
	int t, N, C;
	cin >> t;
	// //
	for (int i = 0; i < t; i++) {
		cin >> N >> C;
		int index = 0; bool result = false;
		int* array = new int[N * C];
		int* car = new int[C];
		int* block = new int[C];
		for (int j = 0; j < N * C; j++) { // input to array
			cin >> array[j];
		}
		for (int j = 0; j < C; j++) { // initialize car and block
			block[j] = 0;
		}

		// // // //
		for (int j = 0; j < N * C; j++) {
			for (int k = 0; k <= index; k++) {
				// k == index�� ���, ���ο� ���Ҹ� �߰��ؾ���
				if (k == index) {
					car[k] = array[j];
					block[k]++;
					index++;
					break;
				}
				// k != index�� ���, k++ �ϰų� ���� ���Ұ� ������ block ++
				else if (array[j] == car[k]) {
					if (k == 0) {
						block[k]++;
						break;
					}
					else {
						block[k]++;
						if (block[k] > block[k - 1]) result = true;
						break;
					}
				}
			}
		}
		// // // //
		delete[] array;
		delete[] car;
		delete[] block;
		if (result == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	} // //
	return 0;
}