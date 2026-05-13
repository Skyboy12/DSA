#include <bits/stdc++.h>

using namespace std;

struct BigInt {
    static const uint32_t BASE = 1000000000U;
    vector<uint32_t> digits;

    BigInt() = default;
    BigInt(uint64_t value) { *this = value; }

    BigInt& operator=(uint64_t value) {
        digits.clear();
        if (value == 0) {
            return *this;
        }
        while (value > 0) {
            digits.push_back((uint32_t)(value % BASE));
            value /= BASE;
        }
        return *this;
    }

    bool isZero() const {
        return digits.empty();
    }

    void add(const BigInt& other) {
        uint64_t carry = 0;
        size_t n = max(digits.size(), other.digits.size());
        if (digits.size() < n) {
            digits.resize(n, 0);
        }
        for (size_t i = 0; i < n; ++i) {
            uint64_t sum = carry + digits[i];
            if (i < other.digits.size()) {
                sum += other.digits[i];
            }
            digits[i] = (uint32_t)(sum % BASE);
            carry = sum / BASE;
        }
        if (carry > 0) {
            digits.push_back((uint32_t)carry);
        }
    }

    string toString() const {
        if (digits.empty()) {
            return "0";
        }
        ostringstream oss;
        int i = (int)digits.size() - 1;
        oss << digits[i];
        for (--i; i >= 0; --i) {
            oss << setw(9) << setfill('0') << digits[i];
        }
        return oss.str();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    string S;
    cin >> K >> S;

    int n = (int)S.size();
    if (K > n) {
        cout << 0 << '\n';
        return 0;
    }

    int width = K + 1;
    int total = (n + 1) * width;
    vector<BigInt> dp(total), nextDp(total);
    dp[0] = BigInt(1);

    for (char ch : S) {
        fill(nextDp.begin(), nextDp.end(), BigInt());

        for (int bal = 0; bal <= n; ++bal) {
            for (int depth = 0; depth <= K; ++depth) {
                const BigInt& cur = dp[bal * width + depth];
                if (cur.isZero()) {
                    continue;
                }

                if (ch == '(' || ch == '?') {
                    int nb = bal + 1;
                    if (nb <= n && nb <= K) {
                        int nd = max(depth, nb);
                        nextDp[nb * width + nd].add(cur);
                    }
                }

                if ((ch == ')' || ch == '?') && bal > 0) {
                    nextDp[(bal - 1) * width + depth].add(cur);
                }
            }
        }

        dp.swap(nextDp);
    }

    cout << dp[K].toString() << '\n';
    return 0;
}
