#include<iostream>

#define SIZE_A 5000
#define SIZE_B 200000

using namespace std;

long long result_array;

long long A[SIZE_A];
long long B[SIZE_B];
//long long AB[SIZE_A][SIZE_B];

void merge(long long* a, int start, int end);
void mergeSort(long long a[], int start, int end);

int main(void) {
	int t, N, M, K;

	long long RESULT;

	cin >> t;
	// for (int i = 0; i < 5000 * 200000; i++) cout << 123 << endl; 이거 안된다
	for (int i = 0; i < t; i++) {
		
		cin >> N >> M >> K;

		for (int j = 0; j < N; j++) {
			cin >> A[j];
		}
		for (int j = 0; j < M; j++) {
			cin >> B[j];
		}

		mergeSort(A, 0, N - 1);
		mergeSort(B, 0, M - 1);

		

		cout << RESULT << endl;
		/* TIME LIMIT
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				AB[j * M + k] = A[j] * B[k];
			}
			*/
	}
	return 0;
}

void merge(long long* a, int start, int end) {

	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = 0;

	int size = end - start + 1;
	long long* temp = new long long[size];

	while (i <= mid && j <= end) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) temp[k++] = a[i++];
	while (j <= end) temp[k++] = a[j++];

	//Copy all element to original arrays
	for (int i = start; i <= end; i++) a[i] = temp[i - start]; /// /// ///

}

void mergeSort(long long a[], int start, int end) {
	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;
	mergeSort(a, start, mid);
	mergeSort(a, mid + 1, end);
	merge(a, start, end);
}