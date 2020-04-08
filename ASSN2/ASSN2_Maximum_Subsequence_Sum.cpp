#include<iostream>

using namespace std;

int main() {
	int t, N;
	long long temp, current_sum, max_sum;
	long long first_elem;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> N;
		cin >> first_elem; // read A[0] first
		current_sum = max_sum = first_elem;
		for (int j = 1; j < N; j++) {
			cin >> temp;
			current_sum += temp;
			if (current_sum > max_sum) max_sum = current_sum;
			else if (current_sum < 0) {
				current_sum = 0;
			}
			if (temp > max_sum) {
				max_sum = temp;
				current_sum = temp;
			}
			if (temp == 0 && max_sum < 0) max_sum = 0;

		}
		cout << max_sum << endl;
	}
}
