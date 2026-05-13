#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; 
    if (!(cin >> n >> m)) return 0;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    
    bool found = false;
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            cout << i << "\n";
            found = true;
        }
    }
    
    if (!found) {
        cout << 0 << "\n";
    }
    
    return 0;
}
