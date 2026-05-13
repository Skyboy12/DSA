#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int v, e, s; cin >> v >> e >> s;
        queue<int> q;
        vector<int> adj[v + 1];
        for(int i = 0; i < e; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        vector<bool> visited(v + 1, false);
        q.push(s);
        visited[s] = true;
        while(!q.empty()){
            int u = q.front(); q.pop();
            cout << u << " ";
            for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
            }
        }
        cout << endl;
    }
}