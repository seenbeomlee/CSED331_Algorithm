#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t; /* # of trials, t ¡Â 100 */
	int N, M; /* # of rows and columns, 0 < N, M ¡Â 3000 */
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> N >> M;
		long long** DP = new long long* [N];
		int** arr = new int* [N];

		long long* left_DP = new long long[M];
		long long* right_DP = new long long[M];

			for (int j = 0; j < N; j++) {
				DP[j] = new long long[M];
				arr[j] = new int[M];
			}

			for (int j = 0; j < N; j++)
				for (int k = 0; k < M; k++)
					cin >> arr[j][k];
			/**********************************/	
			DP[0][0] = arr[0][0];
			for (int k = 1; k < M; k++) DP[0][k] = DP[0][k - 1] + arr[0][k];

			for (int j = 1; j < N; j++) {
				for (int k = 0; k < M; k++) {
					/*left*/
					if (k == 0) left_DP[k] = DP[j-1][0] + arr[j][0];
					else left_DP[k] = max(left_DP[k - 1] + arr[j][k], DP[j - 1][k] + arr[j][k]);
				}
				for(int k = M - 1; k >= 0; k--) {
					/*right*/
					if (k == M - 1) right_DP[k] = DP[j-1][M - 1] + arr[j][M - 1];
					else right_DP[k] = max(right_DP[k + 1] + arr[j][k], DP[j - 1][k] + arr[j][k]);
					/*merge*/
					DP[j][k] = max(left_DP[k], right_DP[k]);
				}
			}
			
			cout << DP[N - 1][M - 1] << endl;
	}
	return 0;
}