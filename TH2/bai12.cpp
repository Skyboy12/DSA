#include <bits/stdc++.h>

using namespace std;

struct State {
    int u, v, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> nodeColor(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> nodeColor[i];
        }

        vector<vector<vector<int>>> adj(N + 1, vector<vector<int>>(4));
        for (int i = 0; i < M; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u][c].push_back(v);
        }

        auto prevColor = [](int color, int stepMod) {
            int x = color - 1 - stepMod;
            x %= 3;
            if (x < 0) x += 3;
            return x + 1;
        };

        vector<vector<array<int, 3>>> dist(N + 1, vector<array<int, 3>>(N + 1, array<int, 3>{-1, -1, -1}));
        queue<State> q;

        dist[1][2][0] = 0;
        q.push({1, 2, 0});

        int answer = -1;
        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            int d = dist[cur.u][cur.v][cur.r];
            if (cur.u == cur.v) {
                answer = d;
                break;
            }

            int needForFirst = prevColor(nodeColor[cur.v], cur.r);
            int needForSecond = prevColor(nodeColor[cur.u], cur.r);
            int nr = (cur.r + 1) % 3;

            for (int nu : adj[cur.u][needForFirst]) {
                for (int nv : adj[cur.v][needForSecond]) {
                    if (dist[nu][nv][nr] == -1) {
                        dist[nu][nv][nr] = d + 1;
                        q.push({nu, nv, nr});
                    }
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
