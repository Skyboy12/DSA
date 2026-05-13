#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> nextGreater(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && h[st.top()] <= h[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nextGreater[i] = st.top();
        }
        st.push(i);
    }

    vector<int> steps(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        if (nextGreater[i] != -1) {
            steps[i] = 1 + steps[nextGreater[i]];
        }
    }

    while (q--) {
        int start;
        cin >> start;
        cout << steps[start - 1] << '\n';
    }

    return 0;
}