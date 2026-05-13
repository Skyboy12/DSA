#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> sz;
    
    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b]; 
        }
    }
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    if (!(cin >> q)) return 0;
    
    int MAX_N = 100000;
    DSU dsu(MAX_N);
    
    while(q--) {
        int u, v, type;
        cin >> u >> v >> type;
        if (type == 1) {
            dsu.unite(u, v);
        } else if (type == 2) {
            if (dsu.find(u) == dsu.find(v)) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
    
    return 0;
}
