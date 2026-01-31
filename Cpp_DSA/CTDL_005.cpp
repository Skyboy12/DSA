#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> f(n);
    for (auto&x : f) cin >> x;
    int m; cin >> m;
    vector<int> newf;
    for (auto&x : f){
        if (x != m){
            newf.push_back(x);
        }
    }
    for (auto&x : newf){
        cout << x << " ";
    }
    return 0;
}