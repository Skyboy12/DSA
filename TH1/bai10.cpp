#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		int answer = 0;
		for (int i = 0; i + 1 < n; ++i) {
			int x = min(a[i], a[i + 1]);
			int y = max(a[i], a[i + 1]);

			while (x * 2 < y) {
				x *= 2;
				++answer;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}
