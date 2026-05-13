#include <bits/stdc++.h>

using namespace std;

void solution(){
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<long long> dp(n);
    for (int i = 0; i < n; i++) dp[i] = a[i];

    long long max_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        max_sum = max(max_sum, dp[i]);
    }
    cout << max_sum << "\n";
}
int main(){
    int t; cin >> t;
    while(t--){
        solution();
    }
    return 0;
}