#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vector<long long> prefPos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        prefPos[i] = prefPos[i - 1] + max(0LL, x);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefPos[r] - prefPos[l - 1] << '\n';
    }
    return 0;
}