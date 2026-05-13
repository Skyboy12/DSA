#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v;
    int c;
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    vector<int> color_node(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> color_node[i];
    }
    
    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
    
    // dp[u][v][t] = shortest time to reach state where Robot 1 is at u, Robot 2 is at v, and time % 3 == t
    // Since N <= 200, N*N*3 states = 200*200*3 = 120,000 states.
    // BFS is O(V + E) which is fine.
    
    vector<vector<vector<int>>> dist(n + 1, vector<vector<int>>(n + 1, vector<int>(3, -1)));
    queue<tuple<int, int, int>> q;
    
    q.push({1, 2, 0});
    dist[1][2][0] = 0;
    
    while (!q.empty()) {
        auto [u1, u2, t_mod] = q.front();
        q.pop();
        
        int current_time = dist[u1][u2][t_mod];
        
        if (u1 == u2) {
            cout << current_time << "\n";
            return;
        }
        
        int req_c1 = color_node[u2];
        int req_c2 = color_node[u1];
        
        vector<int> next_u1;
        for (auto& edge : adj[u1]) {
            int current_edge_color = edge.c + current_time - 1;
            current_edge_color = (current_edge_color % 3) + 1;
            if (current_edge_color == req_c1) {
                next_u1.push_back(edge.v);
            }
        }
        
        vector<int> next_u2;
        for (auto& edge : adj[u2]) {
            int current_edge_color = edge.c + current_time - 1;
            current_edge_color = (current_edge_color % 3) + 1;
            if (current_edge_color == req_c2) {
                next_u2.push_back(edge.v);
            }
        }
        
        int next_t_mod = (t_mod + 1) % 3;
        for (int n1 : next_u1) {
            for (int n2 : next_u2) {
                if (dist[n1][n2][next_t_mod] == -1) {
                    dist[n1][n2][next_t_mod] = current_time + 1;
                    q.push({n1, n2, next_t_mod});
                }
            }
        }
    }
    
    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
