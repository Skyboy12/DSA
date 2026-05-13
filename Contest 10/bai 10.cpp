#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> board(n);
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
	}

	vector<vector<int>> id(n, vector<int>(n, -1));
	vector<pair<int, int>> cells;
	int king = -1;
	vector<int> knights;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] != '#') {
				id[i][j] = (int)cells.size();
				cells.push_back({i, j});
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (id[i][j] == -1) continue;
			int idx = id[i][j];
			if (board[i][j] == 'T') king = idx;
			if (board[i][j] == 'M') knights.push_back(idx);
		}
	}

	if (king == -1) return cout << -1, 0;
	if (knights.empty()) return cout << 0, 0;

	const vector<pair<int, int>> kingMoves = {
		{-1, -1}, {-1, 0}, {-1, 1},
		{0, -1},           {0, 1},
		{1, -1},  {1, 0},  {1, 1}
	};
	const vector<pair<int, int>> knightMoves = {
		{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
		{1, -2},  {1, 2},  {2, -1},  {2, 1}
	};

	int m = (int)cells.size();
	auto bfs = [&](int start, const vector<pair<int, int>>& moves) {
		vector<array<int, 2>> dist(m, {INF, INF});
		queue<pair<int, int>> q;
		dist[start][0] = 0;
		q.push({start, 0});
		while (!q.empty()) {
			auto [u, p] = q.front(); q.pop();
			auto [r, c] = cells[u];
			for (auto [dr, dc] : moves) {
				int nr = r + dr, nc = c + dc;
				if (nr < 0 || nr >= n || nc < 0 || nc >= n || id[nr][nc] == -1) continue;
				int v = id[nr][nc], np = p ^ 1;
				if (dist[v][np] > dist[u][p] + 1) {
					dist[v][np] = dist[u][p] + 1;
					q.push({v, np});
				}
			}
		}
		return dist;
	};

	auto kingDist = bfs(king, kingMoves);

	vector<array<int, 2>> knightNeed(m, {0, 0});
	for (int s : knights) {
		auto d = bfs(s, knightMoves);
		for (int v = 0; v < m; ++v) {
			for (int p = 0; p < 2; ++p) {
				knightNeed[v][p] = (d[v][p] >= INF || knightNeed[v][p] >= INF)
					? INF : max(knightNeed[v][p], d[v][p]);
			}
		}
	}

	int ans = INF;
	for (int v = 0; v < m; ++v) {
		for (int p = 0; p < 2; ++p) {
			if (kingDist[v][p] >= INF || knightNeed[v][p] >= INF) continue;
			ans = min(ans, max(kingDist[v][p], knightNeed[v][p]));
		}
	}

	cout << (ans >= INF ? -1 : ans);
}
