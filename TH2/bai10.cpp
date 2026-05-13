#include <bits/stdc++.h>

using namespace std;

static const char DIGITS[] = {'2', '3', '5', '7'};

static int digitIndex(char d) {
    if (d == '2') return 0;
    if (d == '3') return 1;
    if (d == '5') return 2;
    return 3;
}

void backtrack(int pos, int len, string& cur, int mask) {
    if (pos == len) {
        if (mask == 15 && cur.back() != '2') {
            cout << cur << '\n';
        }
        return;
    }

    int remaining = len - pos;
    int missing = 4 - __builtin_popcount((unsigned)mask);
    if (remaining < missing) {
        return;
    }

    for (char d : DIGITS) {
        if (pos == len - 1 && d == '2') {
            continue;
        }
        cur[pos] = d;
        backtrack(pos + 1, len, cur, mask | (1 << digitIndex(d)));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int len = 4; len <= n; ++len) {
        string cur(len, '2');
        backtrack(0, len, cur, 0);
    }
    return 0;
}
