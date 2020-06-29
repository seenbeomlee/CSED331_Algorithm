#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m; /* n ¡Â 500: # of vertices, m ¡Â 2,000: # of edgees */
		/* num of vertices = 2 * n */
		/* num of edges = n + m */

class edge {
public:
	int to, capacity;

	edge() { ; }
	edge(int input_to, int input_capacity) {
		to = input_to;
		capacity = input_capacity;
	}
};

/* bfs by assignment3_shortest_cycle */
int bfs(vector<edge>* rnode_list, int* parent) {

    int current = -1;
    vector<bool> visited;
    visited.assign(2 * n, false);

    queue <int> q_list;
    q_list.push(0);
    visited[0] = true;
    parent[0] = -1;

    while (!q_list.empty())
    {
        current = q_list.front();
        for(edge child : rnode_list[current])
        {
            if (visited[child.to] == false && child.capacity > 0)
            {
                q_list.push(child.to);
                parent[child.to] = current;
                visited[child.to] = true;
            }
        }
            q_list.pop();
    }
    /* if sink is visited, there is a path root to sink zz*/
    return visited[2*n-1];
}

int ford_fulkerson(vector<edge>* node_list) {
    int u, v;

    vector<edge>* rnode_list = new vector<edge>[2 * n]; /* make a residential graph for calculate the min-cut */
    for (u = 0; u < 2 * n; u++) rnode_list[u].assign(node_list[u].begin(), node_list[u].end());

    int* parent = new int[2 * n];

    int max_flow = 0;

    /* rnode_list does not needed!! 
        you can change rnode_list to node_list and erase rnode_list */

    while (bfs(rnode_list, parent))
    {
        int path_flow = 10001; /* it means INT_MAX */

        /* find a current path_flow */
        for (v = 2*n-1; v != 0; v = parent[v])
        {
            u = parent[v];

            int cap = 10001; /* it means INT_MAX */
            for (edge temp : rnode_list[u]) {
                if (temp.to == v) cap = temp.capacity;
            }
            path_flow = min(path_flow, cap); /* u -> v capacity '-' */
        }

        /* calculating path capacity */
        for (v = 2*n-1; v != 0; v = parent[v])
        {
            u = parent[v];

            for (edge &temp : rnode_list[u]) {
                if (temp.to == v) temp.capacity -= path_flow; /* u -> v capacity '-' */
            }
            //for (edge &temp : rnode_list[v]) {
                //if (temp.to == u) temp.capacity += path_flow; /* u -> v capacity '+' */
            //}
            
        }
        /* add current path_flow to max_flow */
        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
	int t; /* # of trials */
	//int n, m;
	//int input_node_capacity; /* capacity of each node */
	int u, v, c; /* input for edges u, v < n, 0 < c ¡Â 10,000 */

	/* node num 0: source, node num (n-1): sink */
	/* any 2 node u and v, the number of edges between them is 0 or 1 */

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;

		int* input_node_capacity = new int[n];
		vector<edge>* node_list = new vector<edge>[2 * n];

		/* split node '0' o '0' and '1' , split node 'n-1' to '2(n-1)' and '2n-1' */
		/*                  input   output                  input    output */
		/* bridge them with edge capacity "node_capacity" of n              */
		
		/* 0 --> 2n-1 */

		for (int j = 0; j < n; j++) {
			cin >> input_node_capacity[j];
			edge temp(2 * j + 1, input_node_capacity[j]);
			node_list[2 * j].push_back(temp); /* bridging */
		}

		for (int j = 0; j < m; j++) {
			cin >> u >> v >> c;
			edge temp(2 * v, c);
			node_list[2 * u + 1].push_back(temp); /* not bridging, just common edge */
		}

		/* sorting? */

		cout << ford_fulkerson(node_list) << endl;
	}
}