#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> c(n, vector<long long>(n));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }

    int fullMask = (1 << n);
    const long long INF = (long long)4e18;

    vector<vector<long long>> dp(fullMask, vector<long long>(n, INF));
    vector<vector<int>> parent(fullMask, vector<int>(n, -1));

    dp[1][0] = 0;

    for (int mask = 1; mask < fullMask; mask++) {
        if ((mask & 1) == 0) {
            continue;
        }

        for (int u = 0; u < n; u++) {
            if ((mask & (1 << u)) == 0 || dp[mask][u] == INF) {
                continue;
            }

            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) {
                    continue;
                }

                int newMask = mask | (1 << v);
                long long newCost = dp[mask][u] + c[u][v];
                if (newCost < dp[newMask][v]) {
                    dp[newMask][v] = newCost;
                    parent[newMask][v] = u;
                }
            }
        }
    }

    int endMask = fullMask - 1;
    long long bestCost = INF;
    int lastCity = 0;

    for (int u = 0; u < n; u++) {
        if (dp[endMask][u] == INF) {
            continue;
        }

        long long total = dp[endMask][u] + c[u][0];
        if (total < bestCost) {
            bestCost = total;
            lastCity = u;
        }
    }

    vector<int> pathReverse;
    int curMask = endMask;
    int curCity = lastCity;

    while (!(curMask == 1 && curCity == 0)) {
        pathReverse.push_back(curCity);
        int prevCity = parent[curMask][curCity];
        curMask ^= (1 << curCity);
        curCity = prevCity;
    }
    pathReverse.push_back(0);
    reverse(pathReverse.begin(), pathReverse.end());

    cout << "(";
    for (int i = 0; i < (int)pathReverse.size(); i++) {
        cout << pathReverse[i] + 1;
        if (i + 1 < (int)pathReverse.size()) {
            cout << ", ";
        }
    }
    cout << ", 1)\n";
    cout << bestCost << "\n";

    return 0;
}