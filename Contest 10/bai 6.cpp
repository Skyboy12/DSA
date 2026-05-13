#include <bits/stdc++.h>
using namespace std;

int minSteps(int M, int N, vector<vector<int>>& A) {
    vector<vector<int>> dist(M + 1, vector<int>(N + 1, -1));
    queue<pair<int, int>> q;
    
    q.push({1, 1});
    dist[1][1] = 0;
    
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        
        int val = A[i][j];
        
        int nj = j + val;
        if(nj >= 1 && nj <= N && dist[i][nj] == -1) {
            dist[i][nj] = dist[i][j] + 1;
            q.push({i, nj});
        }
        
        int ni = i + val;
        if(ni >= 1 && ni <= M && dist[ni][j] == -1) {
            dist[ni][j] = dist[i][j] + 1;
            q.push({ni, j});
        }
    }
    
    return dist[M][N];
}

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int M, N;
        cin >> M >> N;
        
        vector<vector<int>> A(M + 1, vector<int>(N + 1));
        
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                cin >> A[i][j];
            }
        }
        
        cout << minSteps(M, N, A) << "\n";
    }
    
    return 0;
}
