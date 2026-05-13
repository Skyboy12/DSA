#include <bits/stdc++.h>

using namespace std;

static long long largestRectangle(const vector<int>& h) {
    int n = (int)h.size();
    stack<int> st;
    long long best = 0;

    for (int i = 0; i <= n; ++i) {
        int cur = (i == n ? 0 : h[i]);
        while (!st.empty() && h[st.top()] > cur) {
            int height = h[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            long long width = i - left - 1;
            best = max(best, 1LL * height * width);
        }
        st.push(i);
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<int> yellow(n), blue(n);
    for (int i = 0; i < n; ++i) {
        cin >> yellow[i];
        blue[i] = m - yellow[i];
    }

    long long ans = max(largestRectangle(yellow), largestRectangle(blue));
    cout << ans << '\n';
    return 0;
}
