#include<iostream>
using namespace std;

long long n_array[1000000]; //size is too big, so we need to make it global variable
long long m_array[100000]; //size is too big, so we need to make it global variable

int main() {
	// list�� query ���� long long���� �޾ƾ� ��, query�� �ϳ� ���� �� ���� binary search�� �����ؼ� output�� ����(log n)

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