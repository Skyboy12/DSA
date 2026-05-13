#include <bits/stdc++.h>
using namespace std;

int findmaxlength(const string &s) {
	int n = (int)s.size();
	if (n == 0) return 0;

	int best = 1;

	for (int center = 0; center < n; ++center) {
		int left = center, right = center;
		while (left >= 0 && right < n && s[left] == s[right]) {
			best = max(best, right - left + 1);
			--left;
			++right;
		}

		left = center;
		right = center + 1;
		while (left >= 0 && right < n && s[left] == s[right]) {
			best = max(best, right - left + 1);
			--left;
			++right;
		}
	}

	return best;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << findmaxlength(s) << '\n';
	}

	return 0;
}
