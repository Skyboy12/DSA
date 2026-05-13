#include <bits/stdc++.h>

using namespace std;

vector<int> parent_node;

void make_set(int v) {
    parent_node.resize(v + 1);
    for (int i = 1; i <= v; i++) {
        parent_node[i] = i;
    }
}

int find_set(int v) {
    if (v == parent_node[v])
        return v;
    return parent_node[v] = find_set(parent_node[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent_node[b] = a;
        return true;
    }
    return false;
}

void process() {
    int v, e;
    cin >> v >> e;
    make_set(v);
    
    bool has_cycle = false;
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        if (!has_cycle) {
            if (!union_sets(x, y)) {
                has_cycle = true;
            }
        }
    }
    
    if (has_cycle) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t; 
    cin >> t;
    while(t--){
        process();
    }
    return 0;
}