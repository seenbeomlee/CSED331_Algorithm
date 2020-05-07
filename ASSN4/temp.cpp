#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

struct Line
{
    long long l, r, y;
    Line() { ; };
    Line(long long a, long long b, long long c)
    {
        l = a;
        r = b;
        y = c;
    }
};

long long maxArea(vector<Line>& hulls)
{
    long long n = hulls.size();
    long long max1, max2, max3;
    long long left, right;
    if (n == 1)
    {
        return (hulls[0].r - hulls[0].l) * hulls[0].y;
    }
    vector<Line> hulls1, hulls2;
    for (long long i = 0; i < n / 2; i++)
    {
        hulls1.push_back(hulls[i]);
    }
    for (long long i = 0; i < n - (n / 2); i++)
    {
        hulls2.push_back(hulls[(n / 2) + i]);
    }
    max1 = maxArea(hulls1);
    max2 = maxArea(hulls2);
    left = (n / 2) - 1;
    right = n / 2;
    long long height = min(hulls[left].y, hulls[right].y);
    max3 = height * (hulls[right].r - hulls[left].l);
    while (left > 0 || right < n - 1)
    {
        if (left == 0)
        {
            right++;
            height = min(height, hulls[right].y);
            max3 = max(max3, height * (hulls[right].r - hulls[left].l));
        }
        else if (right == n - 1)
        {
            left--;
            height = min(height, hulls[left].y);
            max3 = max(max3, height * (hulls[right].r - hulls[left].l));
        }
        else if (hulls[left - 1].y > hulls[right + 1].y)
        {
            left--;
            height = min(height, hulls[left].y);
            max3 = max(max3, height * (hulls[right].r - hulls[left].l));
        }
        else
        {
            right++;
            height = min(height, hulls[right].y);
            max3 = max(max3, height * (hulls[right].r - hulls[left].l));
        }

    }
    return max(max(max1, max2), max3);
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long n, w, l, r, y, res;
        vector<Line> hulls;
        cin >> n >> w;
        for (long long j = 0; j < n; j++)
        {
            cin >> l >> r >> y;
            Line h(l, r, y);
            hulls.push_back(h);
        }
        res = maxArea(hulls);
        cout << res << endl;
    }
    return 0;
}