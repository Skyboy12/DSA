#include <bits/stdc++.h>

using namespace std;
long long dp[5005][5005];
int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int L = n / k + 1;
    int S = n / k;
    int mL = n % k;
    int mS = k - mL;
    for (int i = 0; i <= mL; i++){
        for (int j = 0; j <= mS; j++){
            dp[i][j] = LLONG_MAX;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i <= mL; i++){
        for (int j = 0; j <= mS; j++){
            int pos = i * L + j * S;
            if(j < mS){
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + a[pos + S] - a[pos + 1]);
            }
            if (i < mL){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[pos + L] - a[pos + 1]);
            }
        }
    }
    cout << dp[mL][mS] << endl;
    return 0;
}