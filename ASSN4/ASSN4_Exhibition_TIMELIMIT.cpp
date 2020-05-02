#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;
/* class for items */
class item {

public:
	long long f;
	long long d;
	item() { ; };
	item(long long a, long long b) {
		f = a;
		d = b;
	}
};
/* compare for vector list */
bool comp_due(item &A, item &B) {
	if (A.d < B.d) return false;
	else if (A.d > B.d) return true;
	else return A.f < B.f;
}
/* compare for deque list */
/*
bool comp_fee_due(item &A, item &B) {
	if (A.f < B.f) return true;
	else if (A.f > B.f) return false;
	else return A.d > B.d;
*/
/* compare for set list */
struct comp_fee_due {
	bool operator()(const item& A, const item& B) const{
		if (A.f < B.f) return true;
		else if (A.f > B.f) return false;
		else return A.d > B.d;
	}
};
int main() {
	long long t; /* #trial */
	long long n; /* 0 < #items 300,001 */
	long long fee, deadline; /* contents of the items 0 < fee < 1,000,001 , 0 < d < 100,001 */
	long long count;
	long long RESULT;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<item> list1;
		//deque<item> list2;
		set<item, comp_fee_due> list2;
		count = 1;
		RESULT = 0;
		for (int j = 0; j < n; j++) {
			cin >> fee >> deadline;
			item temp(fee, deadline);
			list1.push_back(temp);
		}
		sort(list1.begin(), list1.end(), comp_due);
		item current = list1.back();
		list1.pop_back();
		list2.insert(current);
		while(!list1.empty()) {
			item prev = current;
			current = list1.back();
			list1.pop_back();
			if (current.d > prev.d) {
				// if(count > prev.d) sort(list2.begin(), list2.end(), comp_fee_due);
				while (count > prev.d) {
					list2.erase(list2.begin());
					count--;
				}
			}
			list2.insert(current);
			count++;
		}
		// sort(list2.begin(), list2.end(), comp_fee_due);
		while (count > current.d) {
			list2.erase(list2.begin());
			count--;
		}
		for (auto& temp : list2)
			RESULT += temp.f;
		cout << RESULT << endl;
	}
	return 0;
}