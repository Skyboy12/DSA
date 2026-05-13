#include <bits/stdc++.h>

using namespace std;

vector<int> parent_node;

void make_set(int max_val) {
    parent_node.resize(max_val + 5);
    for (int i = 1; i <= max_val; i++) {
        parent_node[i] = i;
    }
}

int find_set(int v) {
    if (v == parent_node[v])
        return v;
    return parent_node[v] = find_set(parent_node[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent_node[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; 
    if (cin >> q) {
        make_set(100000);
        
        while (q--) {
            int x, y, z; 
            cin >> x >> y >> z;
            if (z == 1) {
                union_sets(x, y);
            } else if (z == 2) {
                if (find_set(x) == find_set(y)) {
                    cout << 1 << "\n";
                } else {
                    cout << 0 << "\n";
                }
            }
        }
    }
    return 0;
}