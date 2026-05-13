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
    
    bool is_perfect = true;
    vector<bool> visited(v + 5, false);
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            long long cnt_v = 0;
            long long cnt_e_deg = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                cnt_v++;
                cnt_e_deg += adj[curr].size();
                
                for (int next_node : adj[curr]) {
                    if (!visited[next_node]) {
                        visited[next_node] = true;
                        q.push(next_node);
                    }
                }
            }
            
            if (cnt_e_deg != cnt_v * (cnt_v - 1)) {
                is_perfect = false;
                break;
            }
        }
    }
    
    if (is_perfect) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        process();
    }
    return 0;
}