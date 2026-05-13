#include <bits/stdc++.h>

using namespace std;

using i128 = __int128_t;

static void generateLucky(long long value, int length, vector<long long>& lucky) {
    if (length > 10) {
        return;
    }
    if (length > 0) {
        lucky.push_back(value);
    }
    if (length == 10) {
        return;
    }
    generateLucky(value * 10 + 4, length + 1, lucky);
    generateLucky(value * 10 + 7, length + 1, lucky);
}

static void printInt128(i128 value) {
    if (value == 0) {
        cout << 0 << '\n';
        return;
    }
    if (value < 0) {
        cout << '-';
        value = -value;
    }
    string s;
    while (value > 0) {
        s.push_back(char('0' + value % 10));
        value /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;

    vector<long long> lucky;
    generateLucky(0, 0, lucky);
    sort(lucky.begin(), lucky.end());

    i128 ans = 0;
    long long prev = 0;
    for (long long cur : lucky) {
        long long left = max(a, prev + 1);
        long long right = min(b, cur);
        if (left <= right) {
            ans += (i128)cur * (right - left + 1);
        }
        prev = cur;
    }

    printInt128(ans);
    return 0;
}
