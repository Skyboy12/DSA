#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		int n = s1.size();
		int m = s2.size();
		vector<int> prev(m + 1, 0), cur(m + 1, 0);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (s1[i - 1] == s2[j - 1]) {
					cur[j] = prev[j - 1] + 1;
				} else {
					cur[j] = max(prev[j], cur[j - 1]);
				}
			}
			swap(prev, cur);
			cur.assign(m + 1, 0);
		}
		cout << prev[m] << '\n';
	}

	return 0;
}
