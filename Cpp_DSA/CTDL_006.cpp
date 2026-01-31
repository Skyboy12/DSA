#include <bits/stdc++.h>

using namespace std;
bool check(vector<int> newf, int a){
    for(auto x : newf){
        if (x == a){
            return false;
        }
    }
    return true;
}


int main(){
    int n; cin >> n;
    vector<int> f(n);
    for (auto&x : f){
        cin >> x;
    }
    vector<int> newf;
    for (auto&x : f){
        if (check(newf, x)){
            newf.push_back(x);
        }
    }
    for (auto&x : newf){
        cout << x << " ";
    }
    return 0;
}