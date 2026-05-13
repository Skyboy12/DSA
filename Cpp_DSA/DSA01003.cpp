#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> list(n);
        for(auto&x : list){
            cin >> x;
        }
        next_permutation(list.begin(), list.end());
        for(auto x : list){
            cout << x << ' ';
        }
        cout<<endl;
    }
}