#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class edge {
public:
	int to;
	long long weight;
	edge() { ; };
	edge(int v, long long w) { to = v; weight = w; }
};

bool compare(edge A, edge B) {
	if (A.to < B.to) return true;
	else if (A.to == B.to) return A.weight < B.weight;
	else return false;
}

int main() {
	vector<edge> temp;
	temp.push_back(edge(0, 1));
	temp.push_back(edge(1, 5));
	temp.push_back(edge(2, 3));
	temp.push_back(edge(4, 7));
	temp.push_back(edge(0, 3));
	temp.push_back(edge(0, -7));
	temp.push_back(edge(1, 2));
	temp.push_back(edge(1, -3));
	temp.push_back(edge(2, 0));
	temp.push_back(edge(4, -2));
	temp.push_back(edge(5, 7));

	sort(temp.begin(), temp.end(), compare);
	//unique(temp.begin(), temp.end());

	for (auto& q : temp) cout << q.to << " " << q.weight << endl;
}