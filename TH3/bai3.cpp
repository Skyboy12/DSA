#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; 
    if (!(cin >> n >> m)) return;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(n + 1, false);
    
    auto bfs = [&](int start) {
        int count = 0;
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return count;
    };
    
    int s1 = bfs(1);
    int s_max = 0;
    
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            s_max = max(s_max, bfs(i));
        }
    }
    
    cout << s1 + s_max << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
