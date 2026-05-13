#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		sort(s.begin(), s.end());
		bool first = true;
		do {
			if (!first) cout << ' ';
			cout << s;
			first = false;
		} while (next_permutation(s.begin(), s.end()));

		cout << '\n';
	}

	return 0;
}
