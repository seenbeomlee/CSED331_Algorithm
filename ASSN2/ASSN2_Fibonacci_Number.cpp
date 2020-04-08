#include<iostream>

using namespace std;
#define MOD 2147483647
void mult(long long A[2][2], long long B[2][2]);
void cal(long long A[2][2], long long N);
long long fib(long long N);

int main() {
	int t;
	long long input;

	cin >> t;

	// if number > 2147483647 then, number %= 21 47 48 36 47
	for (int i = 0; i < t; i++) {
		cin >> input;
		cout << fib(input) << endl;
	}

	return 0;
}

void mult(long long A[2][2], long long B[2][2]) {
	/* x  y
	   z  w */
	long long x = ((A[0][0] * B[0][0])  + (A[0][1] * B[1][0] )) % MOD;
	long long y = ((A[0][0] * B[0][1])  + (A[0][1] * B[1][1])) % MOD;
	long long z = ((A[1][0] * B[0][0])  + (A[1][1] * B[1][0] )) % MOD;
	long long w = ((A[1][0] * B[0][1])  + (A[1][1] * B[1][1] )) % MOD;

	A[0][0] = x;
	A[0][1] = y;
	A[1][0] = z;
	A[1][1] = w;
}

long long fib(long long N) {
	long long initial_matrix[2][2] = { 1, 1, 1, 0 };
	if (N == 0) return 0;
	cal(initial_matrix, N);
	return initial_matrix[0][1];

}

void cal(long long A[2][2], long long N) {
	if (N == 0 || N == 1) return;

	long long B[2][2] = { 1,1,1,0 };


	if (N % 2 == 1) {
		cal(A, N / 2);
		mult(A, A);
		mult(A, B);
	}
	else {
		cal(A, N / 2);
		mult(A, A);
	}
}