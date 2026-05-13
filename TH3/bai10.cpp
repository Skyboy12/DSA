#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]); // nén đường dẫn
    }
    
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            parent[b] = a;
            return true; 
        }
        return false; // a và b đã cùng tập hợp, nếu lại có cạnh nối chứng tỏ sinh ra chu trình
    }
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    DSU dsu(n);
    bool has_cycle = false;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Kiểm tra xem việc thêm cạnh u-v có tạo chu trình không
        if (!has_cycle) {
            if (!dsu.unite(u, v)) {
                has_cycle = true;
            }
        }
    }
    
    cout << (has_cycle ? "YES\n" : "NO\n");
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
