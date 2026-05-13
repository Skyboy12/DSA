#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<long long> pos(n);
	for (int i = 0; i < n; ++i) cin >> pos[i];

	sort(pos.begin(), pos.end());

	auto canPlace = [&](long long minDist) {
		int used = 1;
		long long last = pos[0];

		for (int i = 1; i < n; ++i) {
			if (pos[i] - last >= minDist) {
				++used;
				last = pos[i];
				if (used >= m) return true;
			}
		}
		return false;
	};

	long long low = 0, high = pos.back() - pos.front(), ans = 0;
	while (low <= high) {
		long long mid = low + (high - low) / 2;
		if (canPlace(mid)) {
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	cout << ans;
	return 0;
}
