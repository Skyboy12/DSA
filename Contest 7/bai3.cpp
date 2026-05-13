#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> h(n);
    for (auto& x : h) cin >> x;
    vector<long long> f(n, 1e18);
    f[0] = 0;
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= min(i, k); j++){
            f[i] = min(f[i], f[i-j] + abs(h[i] - h[i-j]));
        }
    }
    cout << f[n-1] << "\n";
}