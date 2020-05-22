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
		for (int j = 0; j < N; j++) {
			arr[j] = new int[M];
		}

		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
				cin >> arr[j][k];

		long long** col_sum = new long long* [N - d + 1];
		for (int j = 0; j < N - d + 1; j++) col_sum[j] = new long long[M];

		for (int j = 0; j < N - d + 1; j++)
			for (int k = 0; k < M; k++)
				col_sum[j][k] = 0;

		for (int j = 0; j < N - d + 1; j++)
			for (int k = 0; k < M; k++) {
				for (int q = j; q < j + d; q++) col_sum[j][k] += arr[q][k];
			}

		for (int j = 0; j < N - d + 1; j++) {
			for (int k = 0; k < M - d + 1; k++) { /* convol matrix's top left elem */
				RESULT = 0;
				for (int q = k; q < k + d; q++) RESULT += col_sum[j][q];
				cout << RESULT << " ";
			}
			cout << endl;
		}
	}


	return 0;
}