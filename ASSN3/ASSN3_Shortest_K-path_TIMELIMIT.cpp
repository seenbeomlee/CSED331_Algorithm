#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class edge {
public:
	int to;
	long long weight;
	edge() { ; };
	edge(int v, long long w) { to = v; weight = w; }
};

long long temp_list[3000][3000];

void find_result(int V, int E, int k, vector<edge>* edge_list);

int main() {
	int t;
	int V; /* number of vertices 1 ~ 3,000 */
	int E; /* number of edges 0 ~ 500,000 */
	int k; /* number of edges that can be used in shortest path 1 ~ 3,000 */

	int u, v; /* edge e = (u, v, w) w = weight of the edge ( |w| < 2^32 ))*/
	long long w;
	/* two or more edges can h ave same start and end vertice */
	/* input graph can contain negative graph */
	/* find shortest k-path ('0' to 'V-1') in the given 'weighted directed graph' */

	/* i think maybe it is related to 'Bellman Ford Algorithm' => NOPE, i maked new algorithm to solve this problem */
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> V >> E >> k;

		vector<edge>* edge_list = new vector<edge>[V]; // dont forget to free

		for (int m = 0; m < 3000; m++)
			for (int n = 0; n < 3000; n++)
				temp_list[m][n] = RAND_MAX;

		for (int j = 0; j < E; j++) {
			cin >> u >> v >> w;
			if(temp_list[u][v] > w) temp_list[u][v] = w;
			/* check if there is edge which has same start and end
			for (edge search : edge_list[u]) {
				if (search.to == v) {
					if (search.weight > w) search.weight = w;
					check = 1;
					break;
				}
			}
			if(check == 0) edge_list[u].push_back(temp);
			check if there is edge which has same start and end */

		}

		for (int m = 0; m < 3000; m++)
			for (int n = 0; n < 3000; n++) {
				if (temp_list[m][n] != RAND_MAX) {
					edge temp(n, temp_list[m][n]);
					edge_list[m].push_back(temp);
				}
			}

		find_result(V, E, k, edge_list);

		delete[] edge_list;
	}

	/* this is okey (no timelimit error)
	for (int m = 0; m < 3000; m++)
		for (int n = 0; n < 3000; n++)
			cout << 123;
			*/


	return 0;
}

void find_result(int V, int E, int k, vector<edge>* edge_list) {

	vector<long long> dist;
	dist.assign(V, RAND_MAX);

	queue<int> vertices_list;

	long long RESULT = RAND_MAX;

	int current = 0;

	int check_block = -1; /* check block to increase 'k' */

	dist[0] = 0;
	vertices_list.push(0);
	vertices_list.push(check_block);

	for (int count = 0; count < k; count++) {
		while (vertices_list.front() != check_block) {
			current = vertices_list.front();
			vertices_list.pop();
			for (edge search : edge_list[current]) {
				vertices_list.push(search.to);
				if (dist[search.to] > dist[current] + search.weight) dist[search.to] = dist[current] + search.weight;
			}
		}
		vertices_list.push(check_block); /* push check_block to back */
		vertices_list.pop(); /* pop check_block from front */
	}

	RESULT = dist[V - 1];
	if (RESULT == RAND_MAX) cout << "NO" << endl;
	else cout << RESULT << endl;
}