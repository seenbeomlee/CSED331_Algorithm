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

bool compare_weight(edge A, edge B) { /* 1 -> 2 -> 3 -> 4 ... */
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

bool parent_same(long long* parent, edge target) {
	long long start_parent = get_parent(parent, target.start);
	long long to_parent = get_parent(parent, target.to);
	if (start_parent == to_parent) return true; /* we need to stop here */
	else return false; /* add new node target.to */
}

void find(deque<edge> edge_list, long long V, long long E, long long K);

void MST(deque<edge> edge_list, long long V, long long E, long long K, edge start_with, long long index);

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

		RESULT = false;
		RES = numeric_limits<long long>::max();

		for (int j = 0; j < E; j++) {
			cin >> u >> v >> c;
			edge temp1(u, v, c);
			edge_list.push_back(temp1);
		}
		sort(edge_list.begin(), edge_list.end(), compare_weight);

		find(edge_list, V, E, K);
	}
	return 0;
}

void find(deque<edge> edge_list, long long V, long long E, long long K) {

	for (int i = 0; i < E; i++) // * E
		MST(edge_list, V, E, K, edge_list[i], i);

	if (RESULT == false) cout << "NO" << endl;
	else cout << RES << endl;
}

void MST(deque<edge> edge_list, long long V, long long E, long long K, edge start_with, long long index) {

	long long sum = start_with.weight;
	long long num_of_same_parent = 2;
	edge target = start_with;
	long long* parent = new long long[V];
	for (int i = 0; i < V; i++) parent[i] = i; // * V
	union_parent(parent, start_with);

	//lower
	for (int i = index; i >= 0; i--) {
		if (target.weight - edge_list[i].weight >= K) {
			if (parent_same(parent, edge_list[i])) continue; /* if it makes cycle, then skip it*/

			target = edge_list[i];

			union_parent(parent, target);
			sum = sum + target.weight;
			num_of_same_parent++;

			if (num_of_same_parent == V) {
				RES = min(RES, sum);
				RESULT = true;
				return;
			}
		}
	}
	//
	target = start_with;
	//upper
	for (int i = index; i < E; i++) {
		if (edge_list[i].weight - target.weight >= K) {
			if (parent_same(parent, edge_list[i])) continue; /* if it makes cycle, then skip it*/

			target = edge_list[i];

			union_parent(parent, target);
			sum = sum + target.weight;
			num_of_same_parent++;

			if (num_of_same_parent == V) {
				RES = min(RES, sum);
				RESULT = true;
				return;
			}
		}
	}
	//
}