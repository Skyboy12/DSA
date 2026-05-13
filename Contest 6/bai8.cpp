#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        cin.ignore();
        string s; getline(cin, s);
        vector<int> char_count(256, 0);
        for (auto x : s){
            char_count[x]++;
        }
        sort(char_count.begin(), char_count.end(), greater<int>());
        char_count.erase(remove(char_count.begin(), char_count.end(), 0), char_count.end());
        while(k--){
            char_count[0]--;
            sort(char_count.begin(), char_count.end(), greater<int>());
            char_count.erase(remove(char_count.begin(), char_count.end(), 0), char_count.end());
        }
        long long result = 0;
        for (auto x : char_count){
            result += (long long)x * x;
        }
        cout << result << endl;
    }
}