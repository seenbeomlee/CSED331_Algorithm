#include<iostream>
#include<algorithm>

using namespace std;

int TSP(int current, int visited, int** arr, int** dp, int n, int m) {

	visited |= (1 << current);

	if (visited == (1 << n) - 1) {
		if (arr[current][0] != 0) return arr[current][0];
		else return 999999;
	}

	if (dp[visited][current] != 0) return dp[visited][current]; /* if already visited route */
	dp[visited][current] = 999999; /* if not visited route */

	for (int i = 0; i < n; i++) {
		if (i != current && !(visited & (1 << i)) && arr[current][i] != 0) {
			dp[visited][current] = min(dp[visited][current], TSP(i, visited, arr, dp, n, m) + arr[current][i]);
		}
	}
	return dp[visited][current];
}

int main() {
	int t; /* # of trials */
	int n, m; /* n == # of nodes 3≤n≤12, m ==  # of edges m≤n(n−1)/2 at most 66 */
	int u, v, c; /* non-directional edge (u,v) with c == cost ≤10,000 */
	int res;
	/* after traveling all cities at once, we should return to the origin */

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;

		int** arr = new int* [n];
		for (int j = 0; j < n; j++) arr[j] = new int[n];
		//memset(arr, 0, n * n * sizeof(int));

		int** dp = new int* [(1 << n)];
		for (int j = 0; j < (1 << n); j++) dp[j] = new int[n];
		//memset(dp, 0, n * n * sizeof(int));

		for(int j = 0 ; j < n; j++)
			for (int k = 0; k < n; k++) {
				arr[j][k] = 0;
			}

		for (int j = 0; j < (1<<n); j++)
			for (int k = 0; k < n; k++) {
				dp[j][k] = 0;
			}

		for (int j = 0; j < m; j++) {
			cin >> u >> v >> c;
			arr[u][v] = c;
			arr[v][u] = c;
		}
		
		res = TSP(0, 0, arr, dp, n, m);
		if (res > 999998) cout << "-1" << endl;
		else cout << res << endl;

		for (int j = 0; j < n; j++) delete arr[j];
		for (int j = 0; j < (1 << n); j++) delete dp[j];
		delete[] arr;
		delete[] dp;
	}

	return 0;
}