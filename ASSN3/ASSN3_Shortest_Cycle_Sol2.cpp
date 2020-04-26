#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void find(int N, vector<int>* list);

int main(void) {
	int t;
	int N, M;
	int from, to;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> N >> M;
		vector<int>* list = new vector<int>[N];

		for (int j = 0; j < M; j++) {
			cin >> from >> to;
			/* add edge to both-side because it is 'undirected graph' */
			list[from].push_back(to);
			list[to].push_back(from);
		}

		find(N, list);
		delete[] list;
	}

	return 0;
}

void find(int N, vector<int>* list) {

	int current = -1;
	int result = 20000;

	for (int i = 0; i < N; i++) {
		vector<int> length;
		length.assign(N, -1);
		/* starting node's length is 0 */
		length[i] = 0;
		vector<int> parent;
		parent.assign(N, -1);
		queue<int> q_list;
		q_list.push(i);

		while (!q_list.empty()) {
			current = q_list.front();
			for (int child : list[current]) {
				/* if length of child == -1, that means we never visited it */
				if (length[child] == -1) {
					length[child] = length[current] + 1;
					q_list.push(child);
					parent[child] = current;
				}
				/* if not, we need to check if there was a bridge between child to child */
				else if (parent[current] != child && parent[child] != current) result = (result < length[child] + length[current] + 1) ? result : length[child] + length[current] + 1;
			}
			q_list.pop();
		}
	}
	/* if we can't find cycle */
	if (result == 20000) cout << -1 << endl;
	/* if we found cycle, print it */
	else cout << result << endl;
}