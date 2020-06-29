/* i didn't solve this problem */

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<time.h>

using namespace std;

class edge {
public:
	int to;
	int capacity;

	edge() { ; };
	edge(int a, int b) {
		to = a;
		capacity = b;
	}
};

int main() {
	int t;
	int n, m, C;
	int u, v, w;
	int max_flow, temp_flow;
	int check;
	int other_count;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> C;

		max_flow = 0;
		temp_flow = 0;
		int* given_cut = new int[C];
		int* given_other = new int[C];
		vector<edge>* list = new vector<edge>[n];

		for (int j = 0; j < C; j++) {
			cin >> given_cut[j]; /* given u */
		}
		
		other_count = 0;
		for (int j = 0; j < n; j++) {
			check = 0;
			for (int k = 0; k < C; k++) {
				if (given_cut[k] == j) check = 1;
			}
			if (!check) {
				given_other[other_count] = j;
				other_count++;
			}
		}

		//cout << "other_cut";
		//for (int z = 0; z < other_count; z++) cout << given_other[z];
		//cout << endl;

		for (int j = 0; j < m; j++) {
			cin >> u >> v >> w;
			edge temp(v, w);
			list[u].push_back(temp);
		}

		/*****C, given_cut --- given_other, other_count***************************************/

		for (int j = 0; j < C; j++) {
			for (edge temp : list[given_cut[j]]) {
				check = 0;
				for (int k = 0; k < C; k++) {
					if (temp.to == given_cut[k]) check = 1;
				}
				if(check == 0) temp_flow += temp.capacity;
			}
		}
		max_flow = temp_flow;
		//cout << temp_flow << endl;

		for (int z = 0; z < 1024; z++) {
		
			if (temp_flow > max_flow) cout << "NO" << endl;
		}
		
	}

	return 0;
}