#include <iostream>
using namespace std;

int main()
{
	int t;
	int N, C;
	int input;
	cin >> t;
	for (int i = 0; i < t; i++) {
		bool result = false;
		cin >> N >> C;
		int index_c = 0; // 현재까지 채워진 car_num 개수 
		int* array = new int[N * C];
		int* car = new int[C]; // car_num의 첫번째 등장 순서를 기록하는 array
		int* block = new int[C]; // car_num의 등장 개수를 기록하는 array
		for (int i = 0; i < N * C; i++) {
			cin >> input;
			for (int k = 0; k < index_c; k++) {
				if (car[k] == input) {
					block[k]++;
					if (k != 0) {
						if (block[k] > block[k - 1]) result = true;
					}
					break;
				}
				if (k == index_c) {
					car[k] = input;
					block[k]++;
					index_c++;
				}
			} 
		}
		if (result == false) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}