#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> currentTuple;

void backtrack(int position, int startValue) {
	if (position == k) {
		for (int i = 0; i < k; ++i) {
			if (i > 0) cout << ' ';
			cout << currentTuple[i];
		}
		cout << '\n';
		return;
	}

	for (int value = startValue; value <= n; ++value) {
		currentTuple[position] = value;
		backtrack(position + 1, value);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	currentTuple.assign(k, 0);
	backtrack(0, 1);

	return 0;
}
