#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class point {
public:
	int x, y;
	int fishes;

	point() { ; };
	point(int a, int b) {
		x = a;
		y = b;
		fishes = 1;
	}
	bool operator== (point& temp) {
		if (temp.x == x && temp.y == y) return true;
		else return false;
	}
};
/*
bool comp_x_y(point& A, point& B) {
	if (A.x < B.x) return true;
	else if (A.x > B.x) return false;
	else return A.y < B.y;
}
*/
bool comp_x_y(point& A, point& B) {
	int A_max = max(A.x, A.y);
	int B_max = max(B.x, B.y);
	if (A_max < B_max) return true;
	else if (A_max > B_max) return false;
	else {
		if (A.x < B.x) return true;
		else if (A.x > B.x) return false;
		else return A.y < B.y;
	}
}

vector<point> return_point(vector<point> list, point temp1);

int main() {
	int t; /* # of trials, t ¡Â 100 */
	int N; /* # of fish points, 1 ¡Â N ¡Â 1,000 */
	int x, y; /* fish point cordinates, 0 ¡Â x, y ¡Â 1,000,000 */

	//vector<point>::iterator upper;
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
		int RESULT = 1;

		for (point& temp1 : list) {
			vector<point> temp_list = return_point(list, temp1);

			if (temp_list.size() == 0) { /* like (0, 5) */
				continue;
			}

			else {
				for (point temp2 : temp_list) 
					temp1.fishes = max(temp1.fishes, temp2.fishes);
				temp1.fishes++;
				RESULT = max(RESULT, temp1.fishes);
			}
		}

		cout << RESULT << endl;
	}
}

vector<point> return_point(vector<point> list, point temp1) {

	vector<point> temp_list;

	for (point check : list) {
		if (check.x <= temp1.x && check.y <= temp1.y && !(check == temp1)) temp_list.push_back(check);
	}

	return temp_list;
}