#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, long long>> st;
    st.reserve(n);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        long long cnt = 1;
        while (!st.empty() && st.back().first < x) {
            ans += st.back().second;
            st.pop_back();
        }

        if (!st.empty() && st.back().first == x) {
            long long same = st.back().second;
            ans += same;
            cnt = same + 1;
            st.pop_back();
            if (!st.empty()) {
                ans += 1;
            }
        } else {
            if (!st.empty()) {
                ans += 1;
            }
        }

        st.push_back({x, cnt});
    }

    cout << ans << '\n';
    return 0;
}
