#include <iostream>
using namespace std;

int main()
{
	int t, N, C, temp;
	bool result, check = false;
	cin >> t;
	// //
	for (int i = 0; i < t; i++) {
		cin >> N >> C;
		int index = 0;
		int* car = new int[C];
		int* block = new int[C];
		result = check = false;
		for (int j = 0; j < C; j++) { // initialize car and block
			block[j] = 0;
		}

		// // // //
		for (int j = 0; j < N * C; j++) {
			cin >> temp;
			if (check == false) {
				for (int k = 0; k <= index; k++) {
					// k == index�� ���, ���ο� ���Ҹ� �߰��ؾ���
					if (k == index) {
						car[k] = temp;
						block[k]++;
						index++;
						break;
					}
					// k != index�� ���, k++ �ϰų� ���� ���Ұ� ������ block ++
					else if (temp == car[k]) {
						if (k == 0) {
							block[k]++;
							break;
						}
						else {
							block[k]++;
							if (block[k] > block[k - 1]) result = check = true;
							break;
						}
					}
				}
			}
		}
		// // // //
		delete[] car;
		delete[] block;
		if (result == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	} // //
	return 0;
}