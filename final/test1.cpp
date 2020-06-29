/* i solved this problem */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void update(int arr, int* save, int start, int num, int size) {
	int mid = (start + num) / 2 + 1;

	if (start == num) {
		if (save[start] > arr) save[start] = arr;
		return;
	}

	if (save[mid] > arr && save[mid - 1] < arr) {
		save[mid] = arr;
		return;
	}
	else {
		if (arr > save[mid]) {
			update(arr, save, mid, num, size / 2);
		}
		else if (arr < save[mid]) {
			update(arr, save, start, mid - 1, size / 2);
		}
		else {
			return;
		}
	}
}

int main() {
	int t;
	int N;
	int length;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> N;

		int* arr = new int[N];
		int* save = new int[N];
		int save_num = 1;
		int length = 1;

		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}

		save[0] = arr[0];
		for (int j = 1; j < N; j++) {
			if (save[save_num - 1] < arr[j]) {
				save[save_num] = arr[j];
				save_num++;
				length++;
			}
			else if (save[save_num - 1] == arr[j]) continue;
			else {
				update(arr[j], save, 0, save_num-1, save_num);
			}
			//cout << "save arr: ";
			//for (int z = 0; z < save_num; z++) cout << "~" << save[z] << "~";
			//cout << endl;
		}

		cout << length << endl;
	}

	return 0;
}