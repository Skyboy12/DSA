#include <bits/stdc++.h>

using namespace std;

string cutstr(string org, int index_l, int index_r){
    index_l--; index_r--;
    string res = "";
    for(int i = index_l; i <= index_r; i++){
        res += org[i];
    }
    return res;
}

bool ispalindrome(string s){
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

int main(){
    string s; cin >> s;
    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        string cut = cutstr(s, l, r);
        if(ispalindrome(cut)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}