#include<iostream>
using namespace std;

long long n_array[1000000]; //size is too big, so we need to make it global variable
long long m_array[100000]; //size is too big, so we need to make it global variable

int main() {
	// list와 query 숫자 long long으로 받아야 함, query를 하나 받을 때 마다 binary search를 수행해서 output을 낸다(log n)

	long long t, temp_n, temp_m;
	int n, m;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;

		for (int j = 0; j < n; j++) cin >> n_array[j];
		for (int j = 0; j < m; j++) cin >> m_array[j];
	}

	return 0;
}