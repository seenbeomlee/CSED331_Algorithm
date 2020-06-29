#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int res;

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

void find(vector<clause> list, vector<int> text, int n, int k, int count1, int num1) {
	/* text starts with index 1 to n */
	if (n > k) return;

	int count = count1;
	int num = num1;

	if (num >= k) return;

	if (count == n) {
		while (num != k) {
			if (list[num].s1 < 0) {
				if (text[abs(list[num].s1)] != 0) return;
			}
			else if (list[num].s1 >= 0) {
				if (text[abs(list[num].s1)] == 0) return;
			}
			if (list[num].s2 < 0) {
				if (text[abs(list[num].s2)] != 0) return;
			}
			else if (list[num].s2 >= 0) {
				if (text[abs(list[num].s2)] == 0) return;
			}
			if (list[num].s3 < 0) {
				if (text[abs(list[num].s3)] != 0) return;
			}
			else if (list[num].s3 >= 0) {
				if (text[abs(list[num].s3)] == 0) return;
			}
			num++;
		}
		res = 1;
		return;
	}

	int check1 = 0;
	int correct1 = 0;
	int check2 = 0;
	int correct2 = 0;
	int check3 = 0;
	int correct3 = 0;

	int go = 1;

	if (text[abs(list[num].s1)] != -1) {
		check1 = 1;
		if (list[num].s1 < 0) {
			if (text[abs(list[num].s1)] == 0) correct1 = 1;
		}
		else if (list[num].s1 >= 0) {
			if (text[abs(list[num].s1)] != 0) correct1 = 1;
		}
	}
	if (text[abs(list[num].s2)] != -1) {
		check2 = 1;
		if (list[num].s2 < 0) {
			if (text[abs(list[num].s2)] == 0) correct2 = 1;
		}
		else if (list[num].s2 >= 0) {
			if (text[abs(list[num].s2)] != 0) correct2 = 1;
		}
	}
	if (text[abs(list[num].s3)] != -1) {
		check3 = 1;
		if (list[num].s3 < 0) {
			if (text[abs(list[num].s3)] == 0) correct3 = 1;
		}
		else if (list[num].s3 >= 0) {
			if (text[abs(list[num].s3)] != 0) correct3 = 1;
		}
	}

	if (check1 == 1 && check2 == 1 && check3 == 1) {
		if (correct1 == 0 && correct2 == 0 && correct3 == 0) return;
	}

	if (check1 == 0 && check2 == 0 && check3 == 0) {

			num++;
			count++;
			if (list[num].s1 < 0) {
				text[abs(list[num].s1)] = 0;
			}
			else if (list[num].s1 >= 0) {
				text[abs(list[num].s1)] = 1;
			}
			find(list, text, n, k, count, num);
			
			if (res == 0) {

				text[abs(list[num].s1)] = -1;

				if (list[num].s2 < 0) {
					text[abs(list[num].s2)] = 0;
				}
				else if (list[num].s2 >= 0) {
					text[abs(list[num].s2)] = 1;
				}
				find(list, text, n, k, count, num);
			}

			if (res == 0) {

				text[abs(list[num].s2)] = -1;

				if (list[num].s3 < 0) {
					text[abs(list[num].s3)] = 0;
				}
				else if (list[num].s3 >= 0) {
					text[abs(list[num].s3)] = 1;
				}
				find(list, text, n, k, count, num);
			}
	}
	else {
		num++;
		find(list, text, n, k, count, num);
	}

	return;
}

int main() {
	
	int t;
	int n; /* (1¡Ân¡Â20) # of bulbs */
	int k; /* (1¡Âk¡Â1000) # of clauses */
	int s1, s2, s3;
	int count; /* # of checked bulbs */
	int num; /* # of checked clauses */
	//long long text; /* it means n => 101 == n1 = 1, n2 = 0, n3 = 1 */
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;

		vector<clause> list;
		vector<int> text;
		count = 0;
		num = 0;
		res = 0;
		text.assign(n+1, -1);

		for (int j = 1; j < k + 1; j++) {
			cin >> s1 >> s2 >> s3;
			list.push_back(clause(s1, s2, s3));
		}

		find(list, text, n, k, count, num);

		if (res == 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}