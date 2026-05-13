#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20005;
vector<int> adj[MAXN];
int num[MAXN], low[MAXN];
int timer = 0;
int split_count[MAXN];

void dfs(int u, int p, int root, int &children_of_root) {
    num[u] = low[u] = ++timer;
    int c = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            if (u == root) {
                children_of_root++;
            }
            dfs(v, u, root, children_of_root);
            low[u] = min(low[u], low[v]);
            if (u != root && low[v] >= num[u]) {
                c++;
            }
        }
    }
    if (u != root) {
        split_count[u] = c + 1;
    } else {
        split_count[u] = children_of_root;
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
        
        int original_components = 0;
        for (int i = 1; i <= n; i++) {
            if (!num[i]) {
                original_components++;
                int children_of_root = 0;
                dfs(i, 0, i, children_of_root);
            }
        }
        
        for (int i = 1; i <= n; i++) {
            cout << original_components - 1 + split_count[i] << "\n";
        }
    }
    return 0;
}
