#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

/* a weighted undirected graph G */
bool RESULT;
long long RES;

class edge {
public:
	long long start;
	long long to;
	long long weight;
	edge() { ; };
	edge(long long x, long long y, long long z) {
		start = x;
		to = y;
		weight = z;
	}
};

bool compare(edge A, edge B) { /* 1 -> 2 -> 3 -> 4 ... */
	if (A.weight < B.weight) return true;
	else return false;
}

long long get_parent(long long* parent, long long x) {
	if (parent[x] == x) return x;
	return parent[x] = get_parent(parent, parent[x]);
}
void union_parent(long long* parent, edge target) {
	long long start_parent = get_parent(parent, target.start);
	long long to_parent = get_parent(parent, target.to);
	if (start_parent < to_parent) parent[to_parent] = start_parent;
	else parent[start_parent] = to_parent;
}

bool find_parent(long long* parent, edge target) {
	long long start_parent = get_parent(parent, target.start);
	long long to_parent = get_parent(parent, target.to);
	if (start_parent == to_parent) return true; /* we need to stop here */
	else return false; /* add new node target.to */
}

void find(deque<edge> edge_list, long long V, long long E, long long K, long long *parent, edge target, long long sum, int num_of_same_parent, int index);

int main() {
	long long t; /* # trials */

	long long V; /* V: # of vertices. ( 2¡ÂN¡Â3,000 ) */
	long long E; /* E: # of edges. ( 1¡ÂM¡Â100,000 ) */
	long long K; /* K: The minimum-gap between edge weights ( 0¡ÂK¡Â100 ) */

	long long u, v; /* 0¡Âu,v<N  (Vertex id starts from 0) */
	long long c; /* 0<c¡Â1,000,000 */

	/* All edge weights are distinct. => use it to distunguish graphs whether they are same or not */
	/* There can be only 1 edge between a pair of vertices. */
	/* The weight difference between any pair of edges in T >= K */

	/* Print out the sum of the edge weights of a K-jump MST. */
	/* If the graph is not connected or there is no K-jump Spanning Tree in the graph, print "NO". */

	cin >> t;
	for (int i = 0; i < t; i++) {
		deque<edge> edge_list;

		RESULT = false;
		RES = numeric_limits<long long>::max();

		cin >> V >> E >> K;

		for (int j = 0; j < E; j++) {
			cin >> u >> v >> c;
			edge temp(u, v, c);
			edge_list.push_back(temp);
		}
		sort(edge_list.begin(), edge_list.end(), compare);

		long long* parent = new long long[V];
		for (int j = 0; j < V; j++) parent[j] = j;

		edge target = edge_list.front();
		long long sum = 0;
		int num_of_same_parent = 1;
		int index = 1;
		find(edge_list, V, E, K, parent, target, sum, num_of_same_parent, index);

		if (RESULT == false) cout << "NO" << endl;
		else cout << RES << endl;
	}

	return 0;
}

void find(deque<edge> edge_list, long long V, long long E, long long K, long long *parent, edge target, long long sum, int num_of_same_parent, int index) {
	if (find_parent(parent, target)) {
		//cout << "not answer: " << sum << endl;
		return; /* we are done */
	}

	else {
		union_parent(parent, target);
		sum = sum + target.weight;
		num_of_same_parent++;
		
		if (num_of_same_parent == V) {
			RES = min(RES, sum);
			RESULT = true;
			return;
		}

		for (int i = index; i < E - (V - num_of_same_parent - 1); i++) {
			if (edge_list[i].weight - target.weight >= K) {
				long long* list = new long long[V];
				for (int j = 0; j < V; j++) list[j] = parent[j];
				find(edge_list, V, E, K, list, edge_list[i], sum, num_of_same_parent, i+1);
			}
			else continue;
		}
		
	}
}