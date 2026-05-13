#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> house(n);
        for (auto& x : house) cin >> x;
        long long prev2 = 0;
        long long prev1 = house[0];
        for (int i = 1; i < n; ++i) {
            long long curr = max(prev1, prev2 + house[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        cout << prev1 << "\n";
    }
    return 0;
}