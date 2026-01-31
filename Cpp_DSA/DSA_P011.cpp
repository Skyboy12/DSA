#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<char>> visited(n, vector<char>(m, 0));
    auto in_bounds = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    };

    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    int components = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                ++components;
                queue<pair<int,int>> q;
                visited[i][j] = 1;
                q.push({i, j});
                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if (in_bounds(nr, nc) && grid[nr][nc] == '#' && !visited[nr][nc]) {
                            visited[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
    }

    cout << components;
    return 0;
}