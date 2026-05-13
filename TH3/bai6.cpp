#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int num[MAXN], low[MAXN];
bool in_stack[MAXN];
stack<int> st;
int timer_dfs = 0, scc_count = 0;

void dfs(int u) {
    num[u] = low[u] = ++timer_dfs;
    st.push(u);
    in_stack[u] = true;

    for (int v : adj[u]) {
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if (num[u] == low[u]) {
        scc_count++;
        while (true) {
            int v = st.top();
            st.pop();
            in_stack[v] = false;
            if (u == v) break;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    timer_dfs = 0;
    scc_count = 0;
    while (!st.empty()) st.pop();

    int max_vertex = n;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        max_vertex = max({max_vertex, edges[i].first, edges[i].second});
    }

    for (int i = 1; i <= max_vertex; i++) {
        adj[i].clear();
        num[i] = 0;
        low[i] = 0;
        in_stack[i] = false;
    }

    for (int i = 0; i < m; i++) {
        adj[edges[i].first].push_back(edges[i].second);
    }

    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            dfs(i);
        }
    }

    cout << scc_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}

