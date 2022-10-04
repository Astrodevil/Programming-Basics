/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

const int inf = (int)1e18;

struct edge {
	int a, b, w;
};

template<typename t>
class Graph {
public:
    vector<vector<pair<t, t>>> adj; // Adjecency List of Graph
    vector<vector<t>> dist; // Distance matrix (Distance of each node to each other node)
    vector<edge> edgeList;
    vector<bool> vis; // Bool array to check if shortest paths from this node is already calulated or not.
    t n, m; // n = number of nodes, m = number of edges

    Graph(t n, t m) : n(n), m(m) { // Constructor to initialize graph with n nodes and m edges
        adj.resize(n + 1); // Initialize adjecenct list for node numbers 1 to n
        dist.resize(n + 1); // Initialize Distance matrix for node numbers 1 to n
        vis.resize(n + 1, 0); // Initialize vis array with 0 marking all nodes unvisited
    }

    void join(t x, t y, t d) { // Join two nodes with an edge of weight d
        adj[x].push_back({y, d});
        edgeList.push_back({x, y, d});
    }

    int BellmanFord (t s, t e) {
    	if (dist[s].size()) return dist[s][e];

    	dist[s].assign(n + 1, inf);
    	dist[s][s] = 0;
    	queue<int> q;
    	for (int i = 0; i < n; i++) {
    		while (!q.empty()) q.pop();
    		for (auto &j: edgeList) {
    			if (dist[s][j.a] < inf) 
    				if (dist[s][j.b] > dist[s][j.a] + j.w) 
    					dist[s][j.b] = max(-inf, dist[s][j.a] + j.w), q.push(j.b);
    		}
    		if (q.empty()) break;
    	}
    	while (!q.empty()) {
    		int u = q.front();
    		q.pop();
    		vis[u] = 1;
    		dist[s][u] = LLONG_MIN;
    		for (auto &v: adj[u]) if (!vis[v.first]) q.push(v.first), vis[v.first] = 1;
    	}
    	return dist[s][e];
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
    int s, e;
    int res = gph.BellmanFord(1, n);
    cout << (res == LLONG_MIN ? -1 : res) << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}