#include <bits/stdc++.h>

using namespace std;

static void generate(int pos, int halfLen, string& half, vector<string>& result) {
    if (pos == halfLen) {
        string full = half;
        for (int i = halfLen - 1; i >= 0; --i) {
            full.push_back(half[i]);
        }
        result.push_back(full);
        return;
    }

    half[pos] = '0';
    generate(pos + 1, halfLen, half, result);

    half[pos] = '1';
    generate(pos + 1, halfLen, half, result);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<string> result;
        for (int len = 2; len <= n; len += 2) {
            string half(len / 2, '0');
            generate(0, len / 2, half, result);
        }

        for (size_t i = 0; i < result.size(); ++i) {
            if (i) {
                cout << ' ';
            }
            cout << result[i];
        }
        cout << '\n';
    }

    return 0;
}
