#include <bits/stdc++.h>

using namespace std;

void able_to_not_repeat(string s){
    vector<int> char_count(256, 0);
    for (auto x : s){
        char_count[x]++;
    }
    int odd_count = 0;
    for (auto x : char_count){
        if (x % 2 == 1) odd_count++;
    }
    if (odd_count > 1) cout << "1\n";
    else cout << "-1\n";
}

int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin.ignore();
        getline(cin, s);
        able_to_not_repeat(s);
    }
    return 0;
}   