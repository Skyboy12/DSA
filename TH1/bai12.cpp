#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	priority_queue<int64, vector<int64>, greater<int64>> pq;
	int64 totalSum = 0;

	for (int i = 0; i < n; ++i) {
		int64 x;
		cin >> x;
		totalSum += x;
		pq.push(x);
	}

	int64 totalCost = 0;
	while (pq.size() > 1) {
		int take = min<int>(k, pq.size());
		int64 currentMin = pq.top();
		int64 currentMax = currentMin;
		int64 currentSum = 0;

		for (int i = 0; i < take; ++i) {
			int64 value = pq.top();
			pq.pop();
			currentSum += value;
			currentMax = value;
		}

		totalCost += currentMax - currentMin;
		pq.push(currentSum);
	}

	cout << totalSum << '\n' << totalCost;
	return 0;
}
