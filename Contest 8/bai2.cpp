#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N), C(N);
    
    for(int i = 0; i < N; i++){
        cin >> A[i] >> C[i];
    }
    vector<int> dp(M + 1, 0);
    for(int i = 0; i < N; i++) {
        for(int j = M; j >= A[i]; j--) {
            dp[j] = max(dp[j], dp[j - A[i]] + C[i]);
        }
    }
    
    cout << dp[M] << "\n";
    
    return 0;
}
