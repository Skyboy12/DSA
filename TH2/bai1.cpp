#include <bits/stdc++.h>

using namespace std;


vector<string> truePairBrackets(string s){
    vector<string> res(s.size());
    stack<pair<char, int>> st;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            st.push({s[i], i});
        } else if (s[i] == ')'){
            if (!st.empty() && st.top().first == '('){
                res[st.top().second] = "0";
                res[i] = "1";
                st.pop();
            } else {
                st.push({s[i], i});
            }
        } else {
            res[i] = s[i];
        }
    }
    while (!st.empty()) {
        res[st.top().second] = "-1";
        st.pop();
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        vector<string> res = truePairBrackets(s);
        for (auto x : res){
            cout << x;
        }
        cout << endl;
    }
    return 0;
}