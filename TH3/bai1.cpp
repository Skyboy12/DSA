#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int v, e, start, end; cin >> v >> e >> start >> end;
        vector<int> adj[v + 1];
        for(int i = 0; i < e; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        vector<bool> visited(v + 1, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        vector<int> path(v + 1, -1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i : adj[u]){
                if(!visited[i]){
                    visited[i] = true;
                    path[i] = u;
                    q.push(i);
                }
            }
        }
        if(!visited[end]) cout << "-1\n";
        else {
            vector<int> res;
            for(int i = end; i != -1; i = path[i]) res.push_back(i);
            reverse(res.begin(), res.end());
            for(int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}