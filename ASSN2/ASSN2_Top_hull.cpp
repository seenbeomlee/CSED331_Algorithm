#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

class line
{
public:

	int lx, rx, y;

	line() { lx = 0; rx = 0; y = 0; };
	line(int a, int b, int c);

	void const reset(int a, int b, int c);
};

line::line(int a, int b, int c) {
	lx = a;
	rx = b;
	y = c;
}

void const line::reset(int a, int b, int c) {
	lx = a;
	rx = b;
	y = c;
}

bool compare(line a, line b) {
	if (a.lx < b.lx) return true;
	else if (a.lx > b.lx) return false;
	else return a.y > b.y;
}

bool compy(line a, line b) {
	return a.y > b.y;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		vector<line> input_list, temp_list, result_list;
		int N;
		cin >> N;

		input_list.reserve(N);
		temp_list.reserve(N);
		result_list.reserve(5 * N);
		for (int j = 0; j < N; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			line temp(a, b, c);
			input_list.push_back(temp);
		}
		sort(input_list.begin(), input_list.end(), compare);
		// initial state //
		line now = input_list[0];
		line comp = input_list[1];
		int next = 1; // prevÀÇ next index
		int start = now.lx;

		line templine;
		while (next < N) {
		here:
			if (now.rx < comp.lx) {
				templine.reset(start, now.rx,  now.y)
					result_list.push_back
			}






		}

	}
	return 0;
}