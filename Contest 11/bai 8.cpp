#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> trace;
bool found_path;

void dfs(int u, int t) {
    visited[u] = true;
    if (u == t) {
        found_path = true;
        return;
    }
    for (int v : adj[u]) {
        if (!visited[v]) {
            trace[v] = u;
            dfs(v, t);
            if (found_path) return;
        }
    }
}

void bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) {
            found_path = true;
            return;
        }
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                trace[v] = u;
                q.push(v);
            }
        }
    }
}

int main(){
    int t_cases; cin >> t_cases;
    while(t_cases--){
        int v, e, s, t; cin >> v >> e >> s >> t;
        adj.assign(v + 5, vector<int>());
        visited.assign(v + 5, false);
        trace.assign(v + 5, -1);
        found_path = false;
        
        for(int i = 0; i < e; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        
        bfs(s, t);
        
        if (found_path) {
            vector<int> path;
            int curr = t;
            while (curr != -1) {
                path.push_back(curr);
                if (curr == s) break;
                curr = trace[curr];
            }
            reverse(path.begin(), path.end());
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}