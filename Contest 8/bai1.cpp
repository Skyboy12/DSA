#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    
    while(T--) {
        int N, V;
        cin >> N >> V;
        vector<int> A(N), C(N);
        
        for(auto& x : A){
            cin >> x;
        }
        for(auto& x : C){
            cin >> x;
        }
        vector<int> dp(V + 1, 0);
        for(int i = 0; i < N; i++) {
            for(int j = V; j >= A[i]; j--) {
                dp[j] = max(dp[j], dp[j - A[i]] + C[i]);
            }
        }
        
        cout << dp[V] << "\n";
    }
    
    return 0;
}
