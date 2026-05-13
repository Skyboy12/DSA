#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int MAX_N = 45;
	vector<int64> len(MAX_N + 1, 0), cntA(MAX_N + 1, 0);

	len[0] = 1;
	len[1] = 1;
	cntA[0] = 1;
	cntA[1] = 0;

	for (int i = 2; i <= MAX_N; ++i) {
		len[i] = len[i - 1] + len[i - 2];
		cntA[i] = cntA[i - 1] + cntA[i - 2];
	}

	auto prefixCountA = [&](int n, int64 k) {
		int64 ans = 0;
		while (k > 0 && n > 1) {
			if (k <= len[n - 1]) {
				n = n - 1;
			} else {
				ans += cntA[n - 1];
				k -= len[n - 1];
				n = n - 2;
			}
		}

		if (k == 0) return ans;
		if (n == 0) return ans + 1;
		return ans;
	};

	int t;
	cin >> t;
	while (t--) {
		int n;
		int64 k;
		cin >> n >> k;
		cout << prefixCountA(n, k) << '\n';
	}

	return 0;
}
