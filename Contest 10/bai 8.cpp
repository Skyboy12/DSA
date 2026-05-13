#include <bits/stdc++.h>
using namespace std;

int minSteps(int N, int M, vector<vector<int>>& A) {
    vector<vector<int>> dist(N + 1, vector<int>(M + 1, -1));
    queue<pair<int, int>> q;

    q.push({1, 1});
    dist[1][1] = 0;
 
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        if (i < N) {
            int stepDown = abs(A[i][j] - A[i + 1][j]);
            int ni = i + stepDown;
            if (stepDown > 0 && ni <= N && dist[ni][j] == -1) {
                dist[ni][j] = dist[i][j] + 1;
                q.push({ni, j});
            }
        }

        if (j < M) {
            int stepRight = abs(A[i][j] - A[i][j + 1]);
            int nj = j + stepRight;
            if (stepRight > 0 && nj <= M && dist[i][nj] == -1) {
                dist[i][nj] = dist[i][j] + 1;
                q.push({i, nj});
            }
        }

        if (i < N && j < M) {
            int stepDiag = abs(A[i][j] - A[i + 1][j + 1]);
            int ni = i + stepDiag;
            int nj = j + stepDiag;
            if (stepDiag > 0 && ni <= N && nj <= M && dist[ni][nj] == -1) {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }

    return dist[N][M];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> A(N + 1, vector<int>(M + 1));

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                cin >> A[i][j];
            }
        }

        cout << minSteps(N, M, A) << "\n";
    }

    return 0;
}
