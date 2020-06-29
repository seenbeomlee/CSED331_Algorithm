#include<iostream>

using namespace std;

void find_stair(long long n, long long m);
void cal(long long A[3][3], long long n, long long m);
void mult(long long A[3][3], long long B[3][3], long long m);

int main() {
	long long t;
	long long n, m;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;

		find_stair(n + 2, m);
		// 1 2 4  
	}

	return 0;
}

void find_stair(long long n, long long m) {
	long long initial_matrix[3][3] = { 1, 1, 1, 1, 0, 0, 0, 1, 0 };
	if (n == 1) {
		cout << 1 % m << endl;
		return;
	}
	else if (n == 2) {
		cout << 2 % m << endl;
		return;
	}
	else if (n == 3) {
		cout << 4 % m << endl;
		return;
	}
	cal(initial_matrix, n - 2, m);
	cout << initial_matrix[0][0] << endl;
	return;
}

void mult(long long A[3][3], long long B[3][3], long long m) {
	/* x1  x2  x3
	   y1  y2  y3
	   z1  z2  z3 */
	long long x1 = (((A[0][0] * B[0][0]) % m) + ((A[0][1] * B[1][0]) % m) + ((A[0][2] * B[2][0]) % m)) % m;
	long long y1 = (((A[1][0] * B[0][0]) % m) + ((A[1][1] * B[1][0]) % m) + ((A[1][2] * B[2][0]) % m)) % m;
	long long z1 = (((A[2][0] * B[0][0]) % m) + ((A[2][1] * B[1][0]) % m) + ((A[2][2] * B[2][0]) % m)) % m;
	
	long long x2 = (((A[0][0] * B[0][1]) % m) + ((A[0][1] * B[1][1]) % m) + ((A[0][2] * B[2][1]) % m)) % m;
	long long y2 = (((A[1][0] * B[0][1]) % m) + ((A[1][1] * B[1][1]) % m) + ((A[1][2] * B[2][1]) % m)) % m;
	long long z2 = (((A[2][0] * B[0][1]) % m) + ((A[2][1] * B[1][1]) % m) + ((A[2][2] * B[2][1]) % m)) % m;

	long long x3 = (((A[0][0] * B[0][2]) % m) + ((A[0][1] * B[1][2]) % m) + ((A[0][2] * B[2][2]) % m)) % m;
	long long y3 = (((A[1][0] * B[0][2]) % m) + ((A[1][1] * B[1][2]) % m) + ((A[1][2] * B[2][2]) % m)) % m;
	long long z3 = (((A[2][0] * B[0][2]) % m) + ((A[2][1] * B[1][2]) % m) + ((A[2][2] * B[2][2]) % m)) % m;

	A[0][0] = x1;
	A[0][1] = x2;
	A[0][2] = x3;

	A[1][0] = y1;
	A[1][1] = y2;
	A[1][2] = y3;

	A[2][0] = z1;
	A[2][1] = z2;
	A[2][2] = z3;
}

void cal(long long A[3][3], long long n, long long m) {
	if (n == 0 || n == 1) return;

	long long temp[3][3] = { 1, 1, 1, 1, 0, 0, 0, 1, 0 };


	if (n % 2 == 1) {
		cal(A, n / 2, m);
		mult(A, A, m);
		mult(A, temp, m);
	}
	else {
		cal(A, n / 2, m);
		mult(A, A, m);
	}
}