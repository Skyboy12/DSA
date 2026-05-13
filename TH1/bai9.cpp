#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	vector<int> sumDiv(b + 1, 0);
	for (int divisor = 1; divisor * 2 <= b; ++divisor) {
		for (int multiple = divisor * 2; multiple <= b; multiple += divisor) {
			sumDiv[multiple] += divisor;
		}
	}

	int answer = 0;
	for (int value = a; value <= b; ++value) {
		if (sumDiv[value] > value) {
			++answer;
		}
	}

	cout << answer;
	return 0;
}
