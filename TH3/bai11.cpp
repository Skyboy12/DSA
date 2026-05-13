#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

void dijkstra(int s, int n, const vector<vector<pair<int, ll>>>& adj, vector<ll>& dist) {
    dist.assign(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    int h1, s1, h2, s2;
    cin >> h1 >> s1 >> h2 >> s2;
    
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<ll> distH1, distS1, distH2, distS2;
    dijkstra(h1, n, adj, distH1);
    dijkstra(s1, n, adj, distS1);
    dijkstra(h2, n, adj, distH2);
    dijkstra(s2, n, adj, distS2);
    
    ll shortestWay1 = distH1[s1];
    ll shortestWay2 = distH2[s2];
    
    int common_nodes = 0;
    bool infinite = false;

    // A valid path for Tí from H1 to S1 passing through u is: distH1[u] + distS1[u] == shortestWay1
    // Same for Tèo: H2 to S2 passing through u requires distH2[u] + distS2[u] == shortestWay2
    
    // Condition for them to meet exactly at node u: 
    // Usually they arrive at u at the SAME TIME: distH1[u] == distH2[u]
    // BUT what if one arrives earlier and is waiting because u IS their school?
    // E.g., if u == s1, Tí waits there. So Tí arrived at distH1[s1] and stays forever.
    // So Tèo arriving at u (s1) at distH2[u] just needs to be >= distH1[s1].
    // Similarly if u == s2, Tèo waits there if distH1[u] >= distH2[s2].
    
    auto is_meeting_point = [&](int u) {
        if (distH1[u] + distS1[u] != shortestWay1) return false;
        if (distH2[u] + distS2[u] != shortestWay2) return false;
        
        if (u != s1 && u != s2) {
            return distH1[u] == distH2[u];
        }
        if (u == s1 && u != s2) {
            return distH2[u] >= distH1[u];
        }
        if (u == s2 && u != s1) {
            return distH1[u] >= distH2[u];
        }
        if (u == s1 && u == s2) {
            return true;
        }
        return false;
    };
    
    for (int i = 1; i <= n; i++) {
        if (is_meeting_point(i)) {
            common_nodes++;
        }
    }
    
    for (int u = 1; u <= n; u++) {
        for (auto& edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (u < v) {
                bool ti_u_v = (distH1[u] + w + distS1[v] == shortestWay1);
                bool teo_u_v = (distH2[u] + w + distS2[v] == shortestWay2);
                bool ti_v_u = (distH1[v] + w + distS1[u] == shortestWay1);
                bool teo_v_u = (distH2[v] + w + distS2[u] == shortestWay2);

                if (ti_u_v && teo_u_v && distH1[u] == distH2[u]) {
                    infinite = true;
                }
                
                if (ti_v_u && teo_v_u && distH1[v] == distH2[v]) {
                    infinite = true;
                }

                if (ti_u_v && teo_v_u) {
                    ll A = distH1[u];
                    ll B = distH2[v];
                    if (abs(A - B) < w) {
                        common_nodes++;
                    }
                }

                if (ti_v_u && teo_u_v) {
                    ll A = distH1[v];
                    ll B = distH2[u];
                    if (abs(A - B) < w) {
                        common_nodes++;
                    }
                }
            }
        }
    }
    
    if (infinite) {
        cout << "infinity\n";
    } else {
        cout << common_nodes << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
