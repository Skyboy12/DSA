#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<long long> a(n + 2, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	vector<int> leftLess(n + 2), rightLess(n + 2);
	stack<int> st;

	for (int i = 1; i <= n; ++i) {
		while (!st.empty() && a[st.top()] >= a[i]) st.pop();
		leftLess[i] = st.empty() ? 0 : st.top();
		st.push(i);
	}

	while (!st.empty()) st.pop();

	for (int i = n; i >= 1; --i) {
		while (!st.empty() && a[st.top()] >= a[i]) st.pop();
		rightLess[i] = st.empty() ? n + 1 : st.top();
		st.push(i);
	}

	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		long long len = rightLess[i] - leftLess[i] - 1;
		ans = max(ans, a[i] * len);
	}

	cout << ans;
	return 0;
}
