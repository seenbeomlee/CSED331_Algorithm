#include<iostream>
#include<vector>
#include<algorithm>

/* put some functions to inside the recursive function is ok */

using namespace std;

class line {
public:
	long long l; /* left-most x */
	long long r; /* right-most x */
	long long y; /* y-coord, 0 < y < 1,000,001 */
	line() { ; };
	line(long long a, long long b, long long c) {
		l = a;
		r = b;
		y = c;
	}
};
/*
bool comp_line(line& A, line& B) { // height < - leftmost-x < sort
	if (A.y < B.y) return false;
	else if (A.y > B.y) return true;
	else return A.l > B.l;
}
*/
/*
line merge(vector<line>* list, line& A, line& B) {
	line temp(A.l, B.y, B.y);

	return temp;
}
*/
long long find( vector<line>& list, long long n);
long long find_min ( long long& a,long long& b, long long& c);
long long find_max ( long long& a, long long& b,  long long& c);

int main() {
	long long t; /* #trials */
	long long n; /* #low-hull segment 0 < n < 500,001 */
	long long w; /* width of city 0 < w < 1,000,001 */
	long long a, b, c; /* for temp line */
	/* the lines are given by increasing order of l */
	/* 0 <= x <= w is the total width of the map */
	/* we must have l == 0 line, and l == x line in the given list */
	/* no overlapping line exists */
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> w;
		vector<line> list;
		for (int j = 0; j < n; j++) {
			cin >> a >> b >> c;
			line temp(a, b, c);
			list.push_back(temp);
		}
		cout << find(list, n) << endl;
	}

	return 0;
}

long long find( vector<line>& list, long long n) {
	if (n == 1) return (list.back().r - list.back().l) * list.back().y;
	vector<line> left_list;
	vector<line> right_list;
	long long R1, R2, R3;
	long long left, right, height;
	left = n / 2 - 1;
	right = n / 2;
	for (int i = 0; i < right; i++) left_list.push_back(list[i]);
	R1 = find(left_list, left_list.size());
	for (int i = right; i < n; i++) right_list.push_back(list[i]);
	R2 = find(right_list, right_list.size());
	/*
	long long height = list[0].y;
	long long leftmost = list[0].l;
	long long rightmost = list.back().r;
	for (auto& temp : list) {
		height = min(height, temp.y);
	}
	R3 = height * (rightmost - leftmost);
	*/
	R3 = min(list[right].y, list[left].y) * (list[right].r - list[left].l);
	height = min(list[right].y, list[left].y);
	while (left != 0 || right != n - 1) {
		height = find_min(list[right].y, list[left].y, height);
		if (left == 0) right++;
		else if (right == n - 1) left--;
		else if (list[right + 1].y >= list[left - 1].y) right++;
		else if (list[right + 1].y < list[left - 1].y) left--;
		R3 = max(R3, (list[right].r - list[left].l) * find_min(list[right].y, list[left].y, height));
	}

	return find_max(R1, R2, R3);
}

long long find_min ( long long& a,  long long& b,  long long& c) {
	if (a <= b && a <= c) return a;
	if (b <= a && b <= c) return b;
	if (c <= a && c <= b) return c;
}

long long find_max ( long long& a,  long long& b,  long long& c) {
	if (a >= b && a >= c) return a;
	if (b >= a && b >= c) return b;
	if (c >= a && c >= b) return c;
}