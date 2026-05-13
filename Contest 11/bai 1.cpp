#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int v, e, s; cin >> v >> e >> s;
        stack<int> st;
        vector<int> adj[v + 1];
        for(int i = 0; i < e; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> visited(v + 1, false);
        st.push(s);
        while(!st.empty()){
            int u = st.top(); st.pop();
            if(!visited[u]){
                cout << u << " ";
                visited[u] = true;
            }
            for(int i = adj[u].size() - 1; i >= 0; i--){
                int v = adj[u][i];
                if(!visited[v]) st.push(v);
            }
        }
        cout << endl;
    }
}