#include <bits/stdc++.h>

using namespace std;

bool check_ratio(int a, int b, int c, int d){
    return (long long)a * d == (long long)b * c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; 
    if (!(cin >> n >> m)) return 0;
    vector<int> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    
    int max_length = 1;
    vector<int> dp(m, 0);
    
    for (int i = 1; i < n; i++){
        vector<int> next_dp(m, 0);
        for (int j = 1; j < m; j++){
            if ((long long)a[i] * b[j-1] == (long long)a[i-1] * b[j]) {
                next_dp[j] = dp[j-1] + 1;
                max_length = max(max_length, next_dp[j] + 1);
            }
        }
        dp = move(next_dp);
    }
    cout << max_length << "\n";
    return 0;
}