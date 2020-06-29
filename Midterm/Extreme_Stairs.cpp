#include<iostream>

using namespace std;

int main() {
	long long t;
	long long n; /* num of stairs */
	long long m; /* result %= m */

	long long first;
	long long second;
	long long third;
	long long current;

	/* she walks up one, two or three steps */
	/* She wins game only when she 'accurately' reachs at the top */

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;

		first = 1;
	    second = 2;
		third = 4;

		if (n == 1) cout << first << endl;
		else if (n == 2) cout << second%m << endl;
		else if (n == 3) cout << third%m << endl;
		else {
			for (int j = 4; j <= n; j++) {
				current = ((first + second) % m + third) % m;
				first = second;
				second = third;
				third = current;
			}
			cout << third << endl;
		}
	}
	return 0;
}