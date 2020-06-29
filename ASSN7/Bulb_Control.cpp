#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

int n; /* (1≤n≤20) # of bulbs = s1, s2, s3, ..., sn */
int k; /* (1≤k≤1000) # of clauses = line1, line2, line3, ..., linek */

class clause {
public:
	int s1, s2, s3;
	clause() { ; }
	clause(int a, int b, int c) {
		s1 = a;
		s2 = b;
		s3 = c;
	}
};

clause list[1000]; /* array of k-clauses */

bool find(int text, int count, int num);

bool check_clause(clause temp, int text) { /* if text == 110001 then, s1 == true, s2 == false, s3 == false, s4 == false, s5 == true, s6 == true */

	if (temp.s1 > 0) {
		if (text & (1 << (temp.s1 - 1)))
			return true;
		}
	else {
		if ((text & (1 << (abs(temp.s1) - 1))) == 0)
			return true;
	}

	if (temp.s2 > 0) {
		if (text & (1 << (temp.s2 - 1)))
			return true;
	}
	else {
		if ((text & (1 << (abs(temp.s2) - 1))) == 0)
			return true;
	}

	if (temp.s3 > 0) {
		if (text & (1 << (temp.s3 - 1)))
			return true;
	}
	else {
		if ((text & (1 << (abs(temp.s3) - 1))) == 0)
			return true;
	}
	
	return false;
}

int main() {
	
	int t;
	int res; /* if res == 1 then YES. if not, NO */

	int s1, s2, s3; /* bulbs which are given from the k-lines */
	/* if s < 0 then 'false' */
	/* if s > 0 then 'true' */
	int count; /* # of checked bulbs */
	int num; /* # of checked clauses */
	int text; /* it means n => 101 == n1 = 1, n2 = 0, n3 = 1 */

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;

		count = 0;
		num = 0;
		text = 0;
		res = 0;

		for (int j = 0; j < k; j++) {
			cin >> s1 >> s2 >> s3;
			clause temp(s1, s2, s3);
			list[j] = temp;
		}

		res = find(text, count, num);

		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}

bool find(int text, int count, int num) {

	bool res;

	for (int i = 0; i < pow(2, n); i++) { /* 여기서 하나라도 통과하면 YES */
		res = false;
		for (int j = 0; j < k; j++) { /* 여기를 모두 통과하면 YES */
			if (check_clause(list[j], text)) {
				if (j == k - 1) res = true;
				continue;
			}
			break;
		}
		if (res == true) return true;
		text++;
	}
	return false;
}