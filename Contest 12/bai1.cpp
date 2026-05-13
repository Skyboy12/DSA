#include <bits/stdc++.h>

using namespace std;

void process() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(1005);
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int interconnected_components = 0;
    vector<bool> visited(1005, false);
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            interconnected_components++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int next_node : adj[u]) {
                    if (!visited[next_node]) {
                        visited[next_node] = true;
                        q.push(next_node);
                    }
                }
            }
        }
    }
    cout << interconnected_components << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        process();
    }
    return 0;
}