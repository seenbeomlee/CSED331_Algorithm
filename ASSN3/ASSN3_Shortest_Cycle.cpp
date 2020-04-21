#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int array[1000][10000];
/***** reference : about vector container in c++ https://blockdmask.tistory.com/70 *****/

class edge {

public: 
	int x, y;
	edge() { x = -1; y = -1; };
	edge(int a, int b) {
		x = a;
		y = b;
	}
};

bool comp(edge A, edge B) {
	if (A.x < B.x) return true;
	else if (A.x == B.x) {
		if (A.y <= B.y) return true;
		else return false;
	}
	else return false;
}

/********************************************************/
/********************************************************/
int shortest_cycle(int n, vector<int>* graph)
{
	// To store length of the shortest cycle 
	int ans = INT_MAX;

	// For all vertices 
	for (int i = 0; i < n; i++) {

		// Make distance maximum 
		vector<int> dist(n, (int)(1e9));

		// Take a imaginary parent 
		vector<int> par(n, -1);

		// Distance of source to source is 0 
		dist[i] = 0;
		queue<int> q;

		// Push the source element 
		q.push(i);

		// Continue until queue is not empty 
		while (!q.empty()) {

			// Take the first element 
			int x = q.front();
			q.pop();

			// Traverse for all it's childs 
			for (int child : graph[x]) {

				// If it is not visited yet 
				if (dist[child] == (int)(1e9)) {

					// Increase distance by 1 
					dist[child] = 1 + dist[x];

					// Change parent 
					par[child] = x;

					// Push into the queue 
					q.push(child);
				}

				// If it is already visited 
				else if (par[x] != child and par[child] != x)
					ans = min(ans, dist[x] + dist[child] + 1);
			}
		}
	}

	// If graph contains no cycle 
	if (ans == INT_MAX)
		return -1;

	// If graph contains cycle 
	else
		return ans;
}
/********************************************************/
/********************************************************/
int main() {

	int t;
	int N, M;
	int a, b;
	int empty_num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		empty_num = 0;
		cin >> N >> M;
		vector<edge> temp_list;
		temp_list.reserve(M);
		for (int j = 0; j < M; j++) {
			cin >> a >> b;
			if (a > b) swap(a, b);
			edge temp_edge(a, b);
			temp_list.push_back(temp_edge);
		}
		sort(temp_list.begin(), temp_list.end(), comp);
		//for (int z = 0; z < 6; z++) cout << temp_list[z].x << temp_list[z].y << endl; //sorted vector list//
		vector<int>* edge_list = new vector<int>[N];

		// make a vector array [start] = end by sorted array 'temp_list'
		for (int j = 0; j < M; j++) {
			int index = temp_list.back().x;
			edge_list[index].push_back(temp_list.back().y);
			temp_list.pop_back();
		}

		for (int j = 0; j < M; j++) if (edge_list[j].empty()) empty_num++; // when we do N = empty_num, we can know how many times we need to calculate (for erase overlapping) //
		/********************************************************/
		cout << shortest_cycle(N - empty_num, edge_list) << endl;
		/********************************************************/

	}
	

	return 0;
}
