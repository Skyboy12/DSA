#include <bits/stdc++.h>

using namespace std;

struct Pos{
    int x, y;
    Pos(string s){
        x = s[0] - 'a';
        y = s[1] - '1';
    }
};

int shortest_path(Pos start, Pos end){
    if (start.x == end.x && start.y == end.y) return 0;

    const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int, int>> q;

    dist[start.x][start.y] = 0;
    q.push({start.x, start.y});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            if (nx == end.x && ny == end.y) return dist[nx][ny];
            q.push({nx, ny});
        }
    }

    return -1;
}

int main(){
    int t; cin >> t;
    while (t--) {
        string s1, s2; cin >> s1 >> s2;
        Pos start(s1), end(s2);
        cout << shortest_path(start, end) << endl;
    }
    return 0;
}