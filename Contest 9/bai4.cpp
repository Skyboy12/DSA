#include <bits/stdc++.h>
using namespace std;

bool isValidBracketSequence(const string &s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char topChar = st.top();
            st.pop();

            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

int max_valid_length(const string &s) {
    stack<int> st;
    st.push(-1);
    int maxLength = 0;

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            st.push(i);
        } else {
            if (!st.empty()) st.pop();
            if (!st.empty()) {
                maxLength = max(maxLength, i - st.top());
            } else {
                st.push(i);
            }
        }
    }

    return maxLength;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << max_valid_length(s) << '\n';
    }

    return 0;
}
