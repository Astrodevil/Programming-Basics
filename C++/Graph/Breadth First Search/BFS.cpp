// Breadth First Search

/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long


template<typename t>
class Graph {
public:
    vector<vector<pair<t, t>>> adj; // Adjecency List of Graph
    vector<vector<t>> dist; // Distance matrix (Distance of each node to each other node)
    vector<bool> vis; // Bool array to check visited nodes.
    t n, m; // n = number of nodes, m = number of edges

    Graph(t n, t m) : n(n), m(m) { // Constructor to initialize graph with n nodes and m edges
        adj.resize(n + 1); // Initialize adjecenct list for node numbers 1 to n
        dist.resize(n + 1); // Initialize Distance matrix for node numbers 1 to n
        vis.resize(n + 1, 0); // Initialize vis array with 0 marking all nodes unvisited
    }

    void join(t x, t y, t d) { // Join two nodes with an edge of weight d
        adj[x].push_back({y, d}); 
        adj[y].push_back({x, d});
    }

    void BFS (int s = 1) {
        queue<t> q; // queue for bfs
        q.push(s); // insert start node
        vis[s] = 1; // mark visited
        while (!q.empty()) {
            t u = q.front(); // store the top element
            q.pop(); // pop the element
            cout << u << " "; // print the element
            for (auto &v: adj[u]) if (!vis[v.first]) q.push(v.first), vis[v.first] = 1; // insert the unvisited adjacent nodes 
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Graph<int> gph(n, m); // declare graph
    for (int i = 0; i < m; i++) {
        int x, y, d; 
        cin >> x >> y >> d; 
        gph.join(x, y, d); // add edges
    }
    gph.BFS();
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}