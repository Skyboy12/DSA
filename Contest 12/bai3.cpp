#include <bits/stdc++.h>

using namespace std;

void process() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v + 5);
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int interconnected_components = 0;
    int largest_component_size = 0;
    vector<int> component_vertices_size;;
    vector<bool> visited(v + 5, false);
    
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            interconnected_components++;
            int current_component_size = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                current_component_size++;
                for (int next_node : adj[u]) {
                    if (!visited[next_node]) {
                        visited[next_node] = true;
                        q.push(next_node);
                    }
                }
            }
            largest_component_size = max(largest_component_size, current_component_size);
        }
    }
    cout << largest_component_size << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        process();
    }
    return 0;
}