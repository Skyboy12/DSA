#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int distinct_count = 0;
    vector<int> char_count(256, 0);
    for (char c : s) {
        if (char_count[c] == 0) distinct_count++;
        char_count[c]++;
    }
    
    vector<int> current_count(256, 0);
    int count = 0;
    int min_len = s.length();
    int start = 0;
    
    for (int i = 0; i < s.length(); i++) {
        current_count[s[i]]++;
        if (current_count[s[i]] == 1) {
            count++;
        }
        
        if (count == distinct_count) {
            while (current_count[s[start]] > 1) {
                current_count[s[start]]--;
                start++;
            }
            min_len = min(min_len, i - start + 1);
        }
    }
    cout << min_len << endl;
}

int main(){
    int t; 
    cin >> t;
    while(t--){
        solve();
    }
}