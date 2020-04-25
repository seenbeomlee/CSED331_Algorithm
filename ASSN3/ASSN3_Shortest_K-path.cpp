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

//long long temp_list[3000][3000];

//
bool compare(edge A, edge B) {
	if (A.to < B.to) return true;
	else if (A.to == B.to) return A.weight < B.weight;
	else return false;
}
//

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

		
		for (int j = 0; j < E; j++) {
			cin >> u >> v >> w;
			edge temp(v, w);
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
			edge_list[u].push_back(temp);
		}
		//
		for (int j = 0; j < V; j++) sort(edge_list[j].begin(), edge_list[j].end(), compare);
		//
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
	dist.assign(V, numeric_limits<long long>::max());

	vector<long long> temp_dist;
	temp_dist.assign(V, numeric_limits<long long>::max());

	queue<int> vertices_list;
	

	//
	vector<int> check;
	check.assign(V, 0);
	////int current_save = -1;
	//
	long long RESULT = numeric_limits<long long>::max();

	int current = 0;

	int check_block = -1; /* check block to increase 'k' */

	temp_dist[0] = 0;
	dist[0] = 0;
	vertices_list.push(0);
	vertices_list.push(check_block);

	for (int count = 0; count < k; count++) {
		while (vertices_list.front() != check_block) {
			current = vertices_list.front();
			vertices_list.pop();
			
			for (edge search : edge_list[current]) {
				/*
				if (check[search.to] == 1) {
					if(current == current_save )continue;
					else {
						current_save = current;
						vertices_list.push(search.to);
						if (temp_dist[search.to] > dist[current] + search.weight) temp_dist[search.to] = dist[current] + search.weight;
					}
				*/
				//
				////check[search.to] = 1;
				////current_save = current;
				//vertices_list.push(search.to);
				if (temp_dist[search.to] > dist[current] + search.weight) temp_dist[search.to] = dist[current] + search.weight;
			}
			for (edge search : edge_list[current]) {
				if (check[search.to] == 1) continue;
				else {
					check[search.to] = 1;
					vertices_list.push(search.to);
				}
			}
			//// ¿Ã∞≈ æ»µ  check.assign(V, 0);
			//// ¿Ã∞≈ æ»µ  for (int index = 0; index < V; index++) check[index] = 0;
		}
		////current_save = -1;
		check.assign(V, 0);
		dist.assign(temp_dist.begin(), temp_dist.end());
		vertices_list.push(check_block); /* push check_block to back */
		vertices_list.pop(); /* pop check_block from front */
	}
	
	RESULT = dist[V - 1];
	if (RESULT == numeric_limits<long long>::max()) cout << "NO" << endl;
	else cout << RESULT << endl;
}