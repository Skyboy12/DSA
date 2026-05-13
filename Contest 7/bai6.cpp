#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<int> dp(n, 1);
    int max_length = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (s[i] >= s[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_length = max(max_length, dp[i]);
    }
    cout << max_length << "\n";
}