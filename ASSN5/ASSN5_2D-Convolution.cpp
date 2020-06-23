#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; /* # of trials, t ¡Â 100 */
	int N, M; /* # of rows and column, 0 < N, M ¡Â 3000 */
	int d; /* convolution matrix will be (n - d + 1, m - d + 1) matrix, 0 < d ¡Â N, M */
	long long RESULT;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> N >> M >> d;

		int** arr = new int* [N];
		long long** DP = new long long* [N];

		for (int j = 0; j < N; j++) {
			arr[j] = new int[M];
			DP[j] = new long long[M];
		}

		for(int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
				cin >> arr[j][k];
		
		DP[0][0] = arr[0][0];

		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				if (j == 0) { /* first row */
					if (k == 0)continue;
					DP[j][k] = DP[j][k - 1] + arr[j][k];
				}
				else if (k == 0) { /* first column */
					DP[j][k] = DP[j - 1][k] + arr[j][k];
				}
				else {
					DP[j][k] = arr[j][k] + DP[j - 1][k] + DP[j][k - 1] - DP[j - 1][k - 1];
				} 
			}
		/*
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++)
				cout << DP[j][k] << " ";
			cout << endl;
		}
		*/
		for (int j = 0; j < N - d + 1; j++) {
			for (int k = 0; k < M - d + 1; k++) {
				if (j == 0 && k == 0)
					cout << DP[j + d - 1][k + d - 1] << " ";
				else if (j > 0 && k == 0)
					cout << DP[j + d - 1][k + d - 1] - DP[j - 1][k + d - 1] << " ";
				else if (j == 0 && k > 0)
					cout << DP[j + d - 1][k + d - 1] - DP[j + d - 1][k - 1] << " ";
				else if(j - 1 >= 0 && k - 1 >= 0)
					cout << DP[j + d - 1][k + d - 1] - DP[j + d - 1 - d][k + d - 1] - DP[j + d - 1][k + d - 1 - d] + DP[j + d - 1 - d][k + d - 1 - d] << " ";
			}
			cout << endl;
		}
	}


	return 0;
}