#include<iostream>
#include<vector>

using namespace std;

int main() {
	int t;
	int N; /* number of rows (2 ~ ) */
	int M; /* number of columns (0 ~ 1000) */
	long long input; /* input S (1 ~ 10^18) the speed limit of (a, b) */
	/* we have a grid[N][M], each value is S */
	/* we need to find a path grid[1][1] to gird[N][M] which can go through by highest speed (not shortest distance. Only speed) */
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> N >> M;
		/* make an array with array[N+1][M+1] */
		long long** array = new long long*[N+1];
		for (int j = 1; j < N+1; j++) array[j] = new long long[M+1];
		/* make an array with array[N+1][M+1] */

		for (int j = 1; j < N+1; j++) {
			for (int k = 1; k < M+1; k++) {
				cin >> input;
				array[j][k] = input;
			}
		}




	}
	return 0;
}
