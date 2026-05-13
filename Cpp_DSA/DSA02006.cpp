#include <bits/stdc++.h>

using namespace std;

void backtrack(const vector<int> &a, int pos, int target, int current_sum,
               vector<int> &chosen, vector<string> &result) {
    if (current_sum == target) {
        string line = "[";
        for (int i = 0; i < (int)chosen.size(); ++i) {
            if (i) line += ' ';
            line += to_string(chosen[i]);
        }
        line += "]";
        result.push_back(line);
        return;
    }

    for (int i = pos; i < (int)a.size(); ++i) {
        if (current_sum + a[i] > target) break;
        chosen.push_back(a[i]);
        backtrack(a, i + 1, target, current_sum + a[i], chosen, result);
        chosen.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end());

        vector<int> chosen;
        vector<string> result;
        backtrack(a, 0, k, 0, chosen, result);

        if (result.empty()) {
            cout << -1;
        } else {
            for (int i = 0; i < (int)result.size(); ++i) {
                if (i) cout << ' ';
                cout << result[i];
            }
        }
        cout << '\n';
    }

    return 0;
}
