#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int t;
	int n, m;
	int temp1, temp2;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		int** arr = new int* [n];
		int** DP = new int* [n];

		for (int j = 0; j < n; j++) {
			arr[j] = new int[m];
			DP[j] = new int[m];
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[j][k];
			}
		}

		DP[0][0] = arr[0][0];

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (j == 0 && k == 0) continue;
				if (j == 0) {
					DP[j][k] = arr[j][k] + DP[j][k - 1];
					continue;
				}
				else if (k == 0) {
					DP[j][k] = arr[j][k] + DP[j - 1][k];
				}
				else if (k == 1 || j == 1) {
					temp1 = max(arr[j][k] + DP[j - 1][k], arr[j][k] + DP[j][k - 1]);
					DP[j][k] = max(temp1, arr[j][k] + DP[j - 1][k - 1]);
				}
				else {
					temp1 = max(arr[j][k] + DP[j - 1][k], arr[j][k] + DP[j][k - 1]);
					temp2 = max(arr[j][k] + DP[j - 1][k - 1], arr[j][k] + DP[j - 2][k - 2]);
					DP[j][k] = max(temp1, temp2);
				}

			}
		}
		cout << DP[n - 1][m -  1] << endl;
	}

	return 0;
}