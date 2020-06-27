#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool find(int start, vector<int>& a_check, vector<int>& b_check, vector<bool>& check, vector<int>* list) {
	if (check[start] == true)
		return false;
	else {
		check[start] = true;

		for (int temp : list[start]) {
			if (b_check[temp] == -1 || find(b_check[temp], a_check, b_check, check, list)) {
				b_check[temp] = start;
				a_check[start] = temp;
				return true;
			}
		}

		return false;
	}
}

int main() {
	int t;
	int n, m, l;
	int start, end;
	int RESULT;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m >> l;

		vector<int>* list = new vector<int>[n];
		vector<int> a_check; a_check.assign(n, -1);
		vector<int> b_check; b_check.assign(m, -1);
		vector<bool> check; check.assign(n, false);
		RESULT = 0;

		for (int j = 0; j < l; j++) {
			cin >> start >> end;
			list[start].push_back(end);
		}

		for (int j = 0; j < n; j++) {
			fill(check.begin(), check.end(), false);

			if (find(j, a_check, b_check, check, list)) RESULT++;
		}
		cout << RESULT << endl;
	}
}