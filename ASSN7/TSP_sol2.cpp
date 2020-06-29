/* using vector (graph) */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class edge {
public:
	int v, c;

	edge() { ; }
	edge(int a, int b) {
		v = a;
		c = b;
	}
};

bool comp_edge(edge& A, edge& B) {
	if (A.v < B.v) return true;
	else return false;
}

int TSP(int current, int visited, vector<edge>* list, int** dp, int n, int m) {

	visited |= (1 << current);

	if (visited == (1 << n) - 1) {
		if (!list[current].empty()) {
			if (list[current].begin()->v == 0) return list[current].begin()->c;
		}
		else return 999999;
	}

	if (dp[visited][current] != 0) return dp[visited][current]; /* if already visited route */
	dp[visited][current] = 999999; /* if not visited route */

	for (edge temp : list[current]) {
		if (!(visited & (1 << temp.v))) {
			dp[visited][current] = min(dp[visited][current], TSP(temp.v, visited, list, dp, n, m) + temp.c);
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

		vector<edge>* list = new vector<edge>[n];
		for (int j = 0; j < m; j++) {
			cin >> u >> v >> c;
			edge temp1(v, c);
			edge temp2(u, c);
			list[u].push_back(temp1);
			list[v].push_back(temp2);
		}
		for (int j = 0; j < n; j++) sort(list[j].begin(), list[j].end(), comp_edge);

		int** dp = new int* [(1 << n)];
		for (int j = 0; j < (1 << n); j++) dp[j] = new int[n];
		for (int j = 0; j < (1 << n); j++)
			for (int k = 0; k < n; k++) {
				dp[j][k] = 0;
			}

		res = TSP(0, 0, list, dp, n, m);

		if (res > 999998) cout << "-1" << endl;
		else cout << res << endl;

		for (int j = 0; j < (1 << n); j++) delete dp[j];
		delete[] dp;
	}

	return 0;
}