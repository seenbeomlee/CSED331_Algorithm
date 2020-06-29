#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;

class edge {
public:
	long long to, weight;

	edge() { ; };
	edge(long long y, long long z) {
		to = y;
		weight = z;
	}
};

bool compare(edge A, edge B) {
	if (A.to < B.to) return true;
	else if (A.to == B.to) return A.weight < B.weight;
	else return false;
}

void find_result(long long V, long long E, vector<edge>* edge_list);

int main() {
	long long t;
	long long V, E;
	long long u, v, c;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> V >> E;

		vector<edge>* edge_list = new vector<edge>[V];

		for (int j = 0; j < E; j++) {
			cin >> u >> v >> c;
			edge temp(v, c);
			edge_list[u].push_back(temp);
		}
		//
		for (int j = 0; j < V; j++) sort(edge_list[j].begin(), edge_list[j].end(), compare);
		//
		find_result(V, E, edge_list);

		delete[] edge_list;
	}

	return 0;
}

void find_result(long long V, long long E, vector<edge>* edge_list) {

	vector<long long>dist;
	dist.assign(V, numeric_limits<long long>::max());

	vector<long long> temp_dist;
	temp_dist.assign(V, numeric_limits<long long>::max());

	deque<long long>* seq_list = new deque<long long>[V];
	queue<int> vertices_list;

	//
	//vector<int> check;
	//check.assign(V, 0);
	//
	int current = 0;

	int check_block = -1;

	temp_dist[0] = 0;
	dist[0] = 0;
	vertices_list.push(0);
	vertices_list.push(check_block);

	for (;;) {
		while (vertices_list.front() != check_block) {
			current = vertices_list.front();
			vertices_list.pop();
			//check[current] = 1;

			for (edge search : edge_list[current]) {
				if (temp_dist[search.to] > dist[current] + search.weight) {
					temp_dist[search.to] = dist[current] + search.weight;

					vertices_list.push(search.to);
					seq_list[search.to].assign(seq_list[current].begin(), seq_list[current].end());
					seq_list[search.to].push_back(current);
				}
			}
			/*
			for (edge search : edge_list[current]) {
				if (check[search.to] == 1) continue;
				else {
					check[search.to] = 1;
					vertices_list.push(search.to);
				}
			}
			*/
		}
		//check.assign(V, 0);
		dist.assign(temp_dist.begin(), temp_dist.end());
		vertices_list.push(check_block); /* push check_block to back */
		vertices_list.pop(); /* pop check_block from front */
		if (vertices_list.front() == check_block) break;
	}

	if (dist[V - 1] == numeric_limits<long long>::max()) cout << "NO";
	else {
		for (long long temp : seq_list[V - 1]) {
			cout << temp << " ";
		}
		cout << V - 1;
	}
	cout << endl;

	return;
}