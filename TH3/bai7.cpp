#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
vector<int> adj[MAXN];
int num[MAXN], low[MAXN];
bool is_cut[MAXN];
int timer_dfs = 0, bridges = 0;

void dfs(int u, int p) {
    int children = 0;
    num[u] = low[u] = ++timer_dfs;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            children++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            
            // Cạnh cầu
            if (low[v] > num[u]) {
                bridges++;
            }
            
            // Đỉnh trụ
            if (u != p && low[v] >= num[u]) {
                is_cut[u] = true;
            }
        }
    }
    // Xét riêng trường hợp u là gốc của cây DFS
    if (u == p && children > 1) {
        is_cut[u] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (cin >> n >> m) {
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for (int i = 1; i <= n; i++) {
            if (!num[i]) {
                // Gọi DFS với u = i và đặt cha của i chính là i (p = i) để đánh dấu nó là gốc
                dfs(i, i);
            }
        }
        
        int cuts = 0;
        for (int i = 1; i <= n; i++) {
            if (is_cut[i]) cuts++;
        }
        
        cout << cuts << " " << bridges << "\n";
    }
    
    return 0;
}
