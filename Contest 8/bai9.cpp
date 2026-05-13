#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;

long long count_ways(vector<int>& arr, long long k) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<long long> dp(k + 1, 0);
    dp[0] = 1;

    for (long long sum = 1; sum <= k; ++sum) {
        for (int num : arr) {
            if (num > sum) break;
            dp[sum] = (dp[sum] + dp[sum - num]) % MOD;
        }
    }

    return dp[k];
}

int main(){
    int t; cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        cout << count_ways(arr, k) << "\n";
    }
    return 0;
}