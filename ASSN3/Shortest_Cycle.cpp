// C++ implementation of the approach 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//#define N 100200 

// Function to find the length of 
// the shortest cycle in the graph 
int shortest_cycle(int n, vector<int>* graph)
{
    // To store length of the shortest cycle 
    int ans = INT_MAX;

    // For all vertices 
    for (int i = 0; i < n; i++) {

        // Make distance maximum 
        vector<int> dist(n, (int)(1e9));

        // Take a imaginary parent 
        vector<int> par(n, -1);

        // Distance of source to source is 0 
        dist[i] = 0;
        queue<int> q;

        // Push the source element 
        q.push(i);

        // Continue until queue is not empty 
        while (!q.empty()) {

            // Take the first element 
            int x = q.front();
            q.pop();

            // Traverse for all it's childs 
            for (int child : graph[x]) {

                // If it is not visited yet 
                if (dist[child] == (int)(1e9)) {

                    // Increase distance by 1 
                    dist[child] = 1 + dist[x];

                    // Change parent 
                    par[child] = x;

                    // Push into the queue 
                    q.push(child);
                }

                // If it is already visited 
                else if (par[x] != child and par[child] != x)
                    ans = min(ans, dist[x] + dist[child] + 1);
            }
        }
    }

    // If graph contains no cycle 
    if (ans == INT_MAX)
        return -1;

    // If graph contains cycle 
    else
        return ans;
}

// Driver code 
int main()
{
    // Number of vertices 
    int t;
    int n, m;
    int x, y;

    cin >> t;
    // Add edges 
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        //vector<vector<int>> gr;
        //gr.reserve(n);
        vector<int>* gr = new vector<int>[n];

        for (int j = 0; j < m; j++) {
            cin >> x >> y;
            if (x > y) swap(x, y);
            gr[x].push_back(y);
            //gr[y].push_back(x);

        }
        cout << shortest_cycle(n, gr) << endl;
    }

    return 0;
}