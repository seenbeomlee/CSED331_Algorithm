/****************************** NOT COMPLETED ******************************/
/****************************** NOT COMPLETED ******************************/
/****************************** NOT COMPLETED ******************************/
/****************************** NOT COMPLETED ******************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class point {
public:
	int x, y;
	long long fishes;

	point() { ; };
	point(int a, int b) {
		x = a;
		y = b;
		fishes = 1;
	}
	bool operator== (point & temp) {
		if (temp.x == x && temp.y == y) return true;
		else return false;
	}
};

bool comp_x_y(point& A, point& B) {
	if (A.x < B.x) return true;
	else if (A.x > B.x) return false;
	else return A.y < B.y;
}

int main() {
	int t; /* # of trials, t ¡Â 100 */
	int N; /* # of fish points, 1 ¡Â N ¡Â 1,000 */
	int x, y; /* fish point cordinates, 0 ¡Â x, y ¡Â 1,000,000 */

	vector<point>::iterator upper;
	/* print the maximum number of fishes the penguin can get*/
	/* penguin only can move to +x and +y */

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> N;

		vector<point> list;

		for (int j = 0; j < N; j++) {
			cin >> x >> y; /* N numbers input for fish point cordinates */
			point temp(x, y);
			list.push_back(temp);
		}

		sort(list.begin(), list.end(), comp_x_y);

		for (point temp1 : list) {
			if (temp1 == list.front) continue;

			upper = upper_bound(list.begin(), list.end(), temp1);
			/* if upper.y > temp1.y */
			if(upper = list.end() || upper.)

			/* else if upper.y < temp1.y */

			/* else upper.y == temp1.y */

			/* if no upper is there ex : (0,5) */
			if (upper == list.end()) continue;
		}
	}


	return 0;
}