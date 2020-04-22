#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/***** reference : about vector container in c++ https://blockdmask.tistory.com/70 *****/

class edge {

public: 
	int x, y;
	edge() { x = -1; y = -1; };
	edge(int a, int b) {
		x = a;
		y = b;
	}

	edge(const edge& A) {
		x = A.x;
		y = A.y;
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
int find(int n, vector<int>* graph)
{
	int result = INT8_MAX;

	for (int i = 0; i < n; i++) {
		if (graph[i].empty()) continue;

		vector<int> length(n, INT8_MAX);
		length[i] = 0;

		queue<int> q_list;
		q_list.push(i);

		// Do BFS
		while (!q_list.empty()) {
			int x = q_list.front();
			q_list.pop();

		for (const auto& child : graph[x]) {
				// If it is not visited yet 
				if (length[child] == INT8_MAX) {
					length[child] = 1 + length[x];
					q_list.push(child);
				}
				// If it is already visited 
				else if (length[child] != INT8_MAX)
					result = min(result, length[x] + length[child] + 1);
			}
		}
	}

	if (result == INT8_MAX) result = -1;
	return result;
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
			index = temp_list.back().y;
			edge_list[index].push_back(temp_list.back().x);
			temp_list.pop_back();

			if (temp_list.empty()) break;
		}

		for (int j = 0; j < N; j++) if (edge_list[j].empty()) empty_num++; // when we do N = empty_num, we can know how many times we need to calculate (for erase overlapping) //

		/* Vector Storage check
		for (int j = 0; j < N - empty_num; j++) {
			cout << "the index : " << j << endl;
			while (!edge_list[j].empty()) {
				int temper;
				temper = edge_list[j].back();
				edge_list[j].pop_back();
				cout << "the number is : "<< temper << endl;
			}
		}
		*/

		/********************************************************/
		cout << find(N, edge_list) << endl;
		/********************************************************/

	}
	return 0;
}
