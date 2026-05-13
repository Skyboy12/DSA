#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> adj[n + 1];
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int q; cin >> q;
        while(q--){
            int begin, end; cin >> begin >> end;
            vector<bool> visited(n + 1, false);
            queue<pair<int, int>> q;
            q.push({begin, 0});
            visited[begin] = true;
            int ans = -1;
            while(!q.empty()){
                auto [u, dist] = q.front(); q.pop();
                if(u == end){
                    ans = dist;
                    break;
                }
                for(int v : adj[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push({v, dist + 1});
                    }
                }
            }
            if (ans != -1) cout << "YES" << endl;
            else cout << "NO" << endl;

        }
    }
}