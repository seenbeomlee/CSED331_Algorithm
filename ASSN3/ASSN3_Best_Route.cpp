#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class edge {
public:
	int to, weight;
	edge() { ; };
	edge(int v, int w) { to = v; weight = w; }
};

//vector<edge> edge_list[3000];
long long find_longest_path(int V, int E, vector<edge>* edge_list, queue<int> t_result);

int main() {
	int t;
	int V; /* 1 ~ 3,000 */
	int E; /* 0 ~ 100,100 which has following form : e = (u, v, w) w = weight(1~INT_MAX) */
	/* two or more edges can have same start and end (u, v) => select higher weight value edge */
	
	int u, v, w; // temporal input
	queue<int> t_temp;
	queue<int> t_result;
	vector<int> degree;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> V >> E;
		vector<edge>* edge_list = new vector<edge>[V]; // dont forget to free

		degree.assign(V, 0);
		for (int j = 0; j < E; j++) {
			cin >> u >> v >> w;
			edge temp = edge(v, w);
			edge_list[u].push_back(temp);
			degree[v]++;
		}
		
		for (int j = 0; j < V; j++) {
			if (degree[j] == 0) t_temp.push(j);
		}

		for (int j = 0; j < V; j++) {
			int x = t_temp.front();
			t_temp.pop();
			t_result.push(x);
			for (edge search : edge_list[x])
				if (--degree[search.to] == 0)
					t_temp.push(search.to);
		}

		/*check for topological sort
		while (!t_result.empty()) {
			cout << "check topology : "<< t_result.front() << endl;
			t_result.pop();
		complete! */

		/* now we have topological sequence in t_result */

		cout << find_longest_path(V, E, edge_list, t_result) << endl;
	}

	return 0;
}

long long find_longest_path(int V, int E, vector<edge>* edge_list, queue<int> t_result) {

	vector<long long>dist;
	dist.assign(V, 0);
	int long long RESULT = -1;

	while (!t_result.empty()) {
		int x = t_result.front();
		t_result.pop();

		for (edge search : edge_list[x]) {
			if (dist[search.to] < dist[x] + search.weight) dist[search.to] = dist[x] + search.weight;
		}
		
	}

	for (long long temp : dist) 
		if (RESULT < temp) RESULT = temp;
	
	return RESULT;
}