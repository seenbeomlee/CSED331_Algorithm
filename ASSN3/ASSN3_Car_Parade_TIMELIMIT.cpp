de<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class block {
public:
	long long S;
	bool check;
	int row;
	int column;
	block() { ; };
};

int main() {
	int t;
	int N; /* number of rows (2 ~ 1000) */
	int M; /* number of columns (2 ~ 1000) */
	long long input; /* input S (1 ~ 10^18) the speed limit of (a, b) */
	long long trial = -1;
	long long RESULT = -1;
	/* we have a grid[N][M], each value is S */
	/* we need to find a path grid[0][0] to gird[N-1][M-1] which can go through by highest speed (not shortest distance. Only speed) */
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> N >> M;
		vector<long long>input_s;
		RESULT = -1;

		/* make an array with array[N+1][M+1] */
		block** S_list = new block * [N];
		for (int j = 0; j < N; j++) S_list[j] = new block[M];
		/* make an array with array[N+1][M+1] */

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> input;
				S_list[j][k].S = input;
				S_list[j][k].row = j;
				S_list[j][k].column = k;
				input_s.push_back(input);
			}
		}
		/* now we have S list in 'input_s' */
		sort(input_s.begin(), input_s.end());
		input_s.erase(unique(input_s.begin(), input_s.end()), input_s.end());
		/* now we have S list in 'input_s' */
		while (!input_s.empty()) {

			trial = input_s.back();
			input_s.pop_back();
			if (trial > S_list[0][0].S || trial > S_list[N - 1][M - 1].S) continue;
			if (trial > S_list[0][1].S&& trial > S_list[1][0].S) continue;
			if (trial > S_list[N - 2][M - 1].S&& trial > S_list[N - 1][M - 2].S) continue;

			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (S_list[j][k].S >= trial) S_list[j][k].check = true;
					else S_list[j][k].check = false;
				}
			}

			queue<block> temp;
			temp.push(S_list[0][0]);

			while (!temp.empty()) {
				block current = temp.front();
				temp.pop();

				if (current.row - 1 >= 0 && S_list[current.row - 1][current.column].check == true) {
					S_list[current.row - 1][current.column].check = false;
					temp.push(S_list[current.row - 1][current.column]);
				}

				if (current.row + 1 < N && S_list[current.row + 1][current.column].check == true) {
					S_list[current.row + 1][current.column].check = false;
					temp.push(S_list[current.row + 1][current.column]);
				}

				if (current.column - 1 >= 0 && S_list[current.row][current.column - 1].check == true) {
					S_list[current.row][current.column - 1].check = false;
					temp.push(S_list[current.row][current.column - 1]);
				}

				if (current.column + 1 < M && S_list[current.row][current.column + 1].check == true) {
					S_list[current.row][current.column + 1].check = false;
					temp.push(S_list[current.row][current.column + 1]);
				}

				if (current.row == N - 1 && current.column == M - 1) {
					RESULT = trial;
					break;
				}
			}
			if (RESULT != -1) break;
		}
		if (RESULT == -1) cout << "NO" << endl;
		else cout << RESULT << endl;


		for (int j = 0; j < N; j++) delete[] S_list[j];
		delete[] S_list;
	}
	return 0;
}
