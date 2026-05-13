#include <bits/stdc++.h>
using namespace std;

int maxTotalValidLength(const string &p) {
    stack<char> st;
    int matchedPairs = 0;

    for (char c : p) {
        if (c == '(') {
            st.push(c);
        } else {
            if (!st.empty()) {
                st.pop();
                matchedPairs++;
            }
        }
    }

    return matchedPairs * 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string p;
        cin >> p;
        cout << maxTotalValidLength(p) << '\n';
    }

    return 0;
}
