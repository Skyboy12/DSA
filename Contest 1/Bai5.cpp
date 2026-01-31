#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int>a(n); 
    for(auto&x : a){
        cin >> x;
    }
    sort(a.begin(), a.end());
    cout << max(abs(a[0] + a[1]), abs(a[n-1] + a[n-2]));
    return 0;
}