#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto count_components = [&](int skip) {
        vector<bool> visited(n + 1, false);
        if (skip != 0) visited[skip] = true;
        
        int comp = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                comp++;
                queue<int> q;
                q.push(i);
                visited[i] = true;
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
            }
        }
        return comp;
    };

    int orig = count_components(0);
    int max_comp = orig;
    int best_u = 0;

    for (int i = 1; i <= n; i++) {
        int c = count_components(i);
        if (c > orig && c > max_comp) {
            max_comp = c;
            best_u = i;
        } else if (c > orig && c == max_comp && best_u == 0) {
            best_u = i; // fallback to smallest index if equal max
        }
    }

    cout << best_u << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}
