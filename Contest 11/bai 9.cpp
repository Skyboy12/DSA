#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

int main() {
    int v, e; 
    while (cin >> v >> e) {
        adj.assign(v + 5, vector<int>());
        for(int i = 0; i < e; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= v; i++) {
            sort(adj[i].begin(), adj[i].end());
        }

        vector<bool> visited_dfs(v + 5, false);
        vector<int> trace_dfs(v + 5, 0);

        function<void(int)> dfs = [&](int u) {
            visited_dfs[u] = true;
            for (int x : adj[u]) {
                if (!visited_dfs[x]) {
                    trace_dfs[x] = u;
                    dfs(x);
                }
            }
        };
        dfs(1);

        for (int i = 2; i <= v; i++) {
            if (!visited_dfs[i]) {
                cout << -1 << endl;
                cout << -1 << endl;
                continue;
            }
            vector<int> path_dfs;
            int curr = i;
            while (curr != 0) {
                path_dfs.push_back(curr);
                if (curr == 1) break;
                curr = trace_dfs[curr];
            }
            reverse(path_dfs.begin(), path_dfs.end());
            for (int node : path_dfs) cout << node << " ";
            cout << endl;

            vector<bool> visited_bfs(v + 5, false);
            vector<int> trace_bfs(v + 5, 0);
            queue<int> q;
            q.push(i);
            visited_bfs[i] = true;
            bool found = false;

            while(!q.empty()) {
                int u = q.front(); q.pop();
                if (u == 1) {
                    found = true;
                    break;
                }
                for (int x : adj[u]) {
                    if (!visited_bfs[x]) {
                        visited_bfs[x] = true;
                        trace_bfs[x] = u;
                        q.push(x);
                    }
                }
            }

            if (found) {
                vector<int> path_bfs;
                int curr2 = 1;
                while (curr2 != 0) {
                    path_bfs.push_back(curr2);
                    if (curr2 == i) break;
                    curr2 = trace_bfs[curr2];
                }
                reverse(path_bfs.begin(), path_bfs.end());
                for (int node : path_bfs) cout << node << " ";
                cout << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}