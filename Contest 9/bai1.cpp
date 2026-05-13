#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--){
        string s;
        getline(cin, s);
        stack<string> st;
        stringstream ss(s);
        string word;
        while (ss >> word){
            st.push(word);
        }
        while (!st.empty()){
            cout << st.top();
            st.pop();
            if (!st.empty()) cout << " ";
        }
        cout << endl;
    }
}