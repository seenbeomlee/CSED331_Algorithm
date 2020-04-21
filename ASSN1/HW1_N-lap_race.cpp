#include<iostream>
using namespace std;
#define size 1000000

int main() {
	int t, N, C, temp, index, result;
	//int car[10000];
	//int block[10000];
	cin >> t;

	for (int i = 0; i < t; i++) { // 차는 0등 -> 1등 -> 2등 ..
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

			if (car[temp - 1] == -1) { // 처음 들어온 차
				car[temp - 1] = index;
				block[car[temp - 1]]++;
				index++;
			}
			else { // 2바퀴 이상 들어온 차
				block[car[temp - 1]]++;

				if (car[temp - 1] != 0) { // 0등은 -1등과 비교할순 없으므로 제외
					if (block[car[temp - 1]] > block[car[temp - 1] - 1]) { // 추월한경우
						result = 1;
						for (int k = j + 1; k < N * C; k++) cin >> temp; // 더 이상 계산할 필요가 없으므로 남은 입력값 버려주기
						break;
					}
					else {// 추월하지못함 
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