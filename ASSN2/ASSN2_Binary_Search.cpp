#include<iostream>
using namespace std;

long long n_array[1000000]; //size is too big, so we need to make it global variable

int main() {
	// list와 query 숫자 long long으로 받아야 함, query를 하나 받을 때 마다 binary search를 수행해서 output을 낸다(log n)

	long long t, target, result;
	long long temp_left, temp_right;
	int n, m;
	int low = 0;
	int mid, high;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		
		for (int j = 0; j < n; j++) cin >> n_array[j];

		for (int j = 0; j < m; j++) {
			cin >> target;

			low = 0;
			high = n - 1;

			while (high >= low) {
				mid = (low + high) / 2;

				if (n_array[mid] == target) {
					result = n_array[mid];
					break;
				}
				else if (n_array[mid] > target) high = mid - 1;
				else low = mid + 1;
			}

			if (high < low) {
				if (low == 0) result = n_array[0];
				else if (high == n - 1) result = n_array[n - 1];
				else {
					temp_left = target - n_array[high];
					temp_right = n_array[low] - target;

					if (temp_left <= temp_right) result = n_array[high];
					else result = n_array[low];
				}
			}

			cout << result << " ";
		}
		cout << endl;
	}
	return 0;
}