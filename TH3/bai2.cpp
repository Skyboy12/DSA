#include <bits/stdc++.h>

using namespace std;

bool dfs(int u, vector<vector<int>>& adj, vector<int>& color) {
    color[u] = 1;
    for (int v : adj[u]) {
        if (color[v] == 1) return true;
        if (color[v] == 0 && dfs(v, adj, color)) return true;
    }
    color[u] = 2;
    return false;
}

void solve() {
    int v, e; cin >> v >> e;
    vector<vector<int>> adj(v + 1);
    for(int i = 0; i < e; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    
    vector<int> color(v + 1, 0);
    bool check = false;
    for (int i = 1; i <= v; i++) {
        if (color[i] == 0) {
            if (dfs(i, adj, color)) {
                check = true;
                break;
            }
        }
    }
    
    cout << (check ? "YES\n" : "NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
