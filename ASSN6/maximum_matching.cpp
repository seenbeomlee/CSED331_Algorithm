
    /* 
        'fill' function makes value of c ~ c + MAX to false

        for (int i = 1; i <= n; i++) {
            fill(c, c + MAX, false);
            if (dfs(i)) count++;
        }
    */

#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_NUM 1000

using namespace std;

//int A[MAX_NUM];
//int B[MAX_NUM];

class line {
public:
    int to;

    line() { ; };
    line(int input) {
        //from;
        to = input;
    }
};

bool comp_to(line& A, line& B) {
    if (A.to < B.to) return false;
    else return true;
}

bool find(int start, int m, vector<int> &a_check, vector<int> &b_check, vector<line>* lines, vector<bool> &check) { /* you must receive vector<> by reference or, it initialized !! */
    if (check[start])
        return false;
    else {
        check[start] = true;

        for (line index : lines[start]) {
            //if (index.to > 1000 || index.to < 0) return false;

            if (b_check[index.to] == -1 || find(b_check[index.to], m, a_check, b_check, lines, check)) {
                a_check[start] = index.to;
                b_check[index.to] = start;
                return true;
            }
        }

        return false;
    }
}

int main() {
    int t;
    int n, m, l;
    int input_from, input_to;
    int res;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m >> l;

        res = 0;
        vector<line>* lines = new vector<line>[n]; /* container for lines */
        vector<int> a_check; a_check.assign(n, -1); /* check vertice of 'A' is connected to what */
        vector<int> b_check; b_check.assign(m, -1); /* check vertice of 'B' is connected to what */
        vector<bool> check; check.assign(n, false); /* check vertice of 'A' is connected or not? */

        for (int j = 0; j < l; j++) {
            cin >> input_from >> input_to;
            line temp(input_to);
            lines[input_from].push_back(temp);
        }

        for (int j = 0; j < n; j++) {
            //if(lines[j].size() > 1)
            sort(lines[j].begin(), lines[j].end(), comp_to);
        }

        for (int j = 0; j < n; j++) {
            //if (lines[j].empty()) continue;

            fill(check.begin(), check.end(), false);

            if (find(j, m, a_check, b_check, lines, check)) {
                res++;
            }
        }

        delete[] lines;

        cout << res << endl;
    }
}