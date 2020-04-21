#include <iostream>
using namespace std;

class Point
{
	long long x, y;

public:
	Point() {};
	Point(long long a, long long b);
	long long length() const;
	double cosine() const;
	void print_point() const;

	long long return_x() const;
	long long return_y() const;
};

Point::Point(long long a, long long b) {
	x = a;
	y = b;
}

long long Point::return_x() const {
	return x;
}

long long Point::return_y() const {
	return y;
}

long long Point::length() const {
	long long length = x * x + y * y;
	return length;
}

double Point::cosine() const {
	double cosine;

	cosine = static_cast<double>(y * y) / static_cast<double>(x * x + y * y);

	if (y < 0) cosine *= -1;

	return cosine;
}

void Point::print_point() const {
	cout << x << " " << y << endl;
}




bool operator<(Point a, Point b) {
	if (a.return_x() >= 0 && b.return_x() < 0) return true;
	else if (a.return_x() < 0 && b.return_x() >= 0) return false;

	else if (a.return_x() == b.return_x() && a.return_y() == b.return_y()) return false;

	else {
		if (a.return_x() >= 0 && b.return_x() >= 0) {
			// 둘 다 x좌표가 양수일 경우
			if (a.cosine() == b.cosine()) return a.length() < b.length();
			else {
				//cosine 값이 작을수록 각이 큰거
				return b.cosine() < a.cosine();
			}
		}
		else  {
			// 둘 다 x좌표가 음수일 경우
			if (a.cosine() == b.cosine()) return a.length() < b.length();
			else {
				//cosine 값이 클을수록 각이 큰거
				return a.cosine() < b.cosine();
			}
		}
	}
}

void merge(Point* a, int start, int end) {

	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = 0;

	int size = end - start + 1;
	Point* temp = new Point[size];

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

void mergeSort(Point a[], int start, int end) {
	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;
	mergeSort(a, start, mid);
	mergeSort(a, mid + 1, end);
	merge(a, start, end);
}

int main(void) {
	int t, num;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> num;
		Point* array = new Point[num];
		for (int j = 0; j < num; j++) {
			long long a, b;
			cin >> a >> b;
			Point temp(a, b);
			array[j] = temp;
		}
		mergeSort(array, 0, num - 1);
		for (int j = 0; j < num; j++) array[j].print_point();
		cout << endl;
	}
	
	//Point a(-1, -1);
	//Point b(3, 2);
	//Point c(3, -2);
	//Point d(2, -3);
	//Point e(-2, -3);
	//Point f(-3, -2);
	//Point g(-3, 2);
	//Point h(-2, 3);
	//Point aa(-2, -2);

	//if (a < aa) cout << "x1 < x2" << endl;
	//else if (aa < a) cout << "x2 < x1" << endl;
	return 0;
}