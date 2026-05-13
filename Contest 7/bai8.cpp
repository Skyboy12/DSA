#include <bits/stdc++.h>

using namespace std;

void solution(){
    int n; cin >> n;
    vector<int> a(n); vector<long long> f(n+1);
    f[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        f[i+1] = f[i] + a[i];
    }
    long long max_sum = f[1] - f[0];
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            max_sum = max(max_sum, f[i] - f[j]);
        }
    }
    cout << max_sum << "\n";
}

int main(){
    int t; cin >> t;
    while (t--){
        solution();
    }
}