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

const int MAX_LIMIT = (int)1e16;

template<typename t>
class Graph {
public:
    vector<vector<pair<t, t>>> adj; // Adjecency List of Graph
    vector<vector<t>> dist; // Distance matrix (Distance of each node to each other node)
    vector<bool> vis; // Bool array to check if shortest paths from this node is already calulated or not.
    t n, m; // n = number of nodes, m = number of edges

    Graph(t n, t m) : n(n), m(m) { // Constructor to initialize graph with n nodes and m edges
        adj.resize(n + 1); // Initialize adjecenct list for node numbers 1 to n
        dist.assign(n + 1, vector<int>(n + 1, MAX_LIMIT)); // Initialize Distance matrix for node numbers 1 to n
        vis.resize(n + 1, 0); // Initialize vis array with 0 marking all nodes unvisited
    }

    void join(t x, t y, t d) { // Join two nodes with an edge of weight d
        adj[x].push_back({y, d}); 
        adj[y].push_back({x, d});
        dist[x][y] = min(dist[x][y], d);
        dist[y][x] = min(dist[y][x], d);
    }

    void FloydWarshall() {
    	for (int i = 1; i <= n; i++) dist[i][i] = 0;
    	for (int i = 1; i <= n; i++) 
    		for (int j = 1; j <= n; j++) 
    			for (int k = 1; k <= n; k++) 
    				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    Graph<int> gph(n, m); // declare graph
    for (int i = 0; i < m; i++) {
        int x, y, d; 
        cin >> x >> y >> d; 
        gph.join(x, y, d); // add edges
    }
    gph.FloydWarshall();
    while (q--) {
    	int x, y;
    	cin >> x >> y;
    	cout << (gph.dist[x][y] == MAX_LIMIT ? -1 : gph.dist[x][y]) << "\n";
    }
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