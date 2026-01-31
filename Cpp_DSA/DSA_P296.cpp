#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    vector<long long> f(n+1, 0);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        f[i] = f[i-1] + x;
    }
    while (q--){
        int l, r;
        cin >> l >> r;
        long long min_prefix = f[l-1];
        long long max_sum = f[l] - f[l-1];
        for(int j = l; j <= r; j++){
            max_sum = max(max_sum, f[j] - min_prefix);
            min_prefix = min(min_prefix, f[j]);
        }
        printf("%lld\n", max_sum);
    }
    return 0;
}