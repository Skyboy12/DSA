#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> list(n);
    for (auto&x : list) cin >> x;
    sort(list.begin(), list.end());
    do{
        for (auto x : list) cout << x << ' ';
        cout << endl;
    } while (next_permutation(list.begin(), list.end()));
    return 0;
}