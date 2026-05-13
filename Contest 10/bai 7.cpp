#include <bits/stdc++.h>

using namespace std;

vector<int> buildPrimes(int limit) {
	vector<bool> isPrime(limit + 1, true);
	isPrime[0] = false;
	if (limit >= 1) {
		isPrime[1] = false;
	}

	for (int i = 2; 1LL * i * i <= limit; i++) {
		if (!isPrime[i]) {
			continue;
		}
		for (int j = i * i; j <= limit; j += i) {
			isPrime[j] = false;
		}
	}

	vector<int> primes;
	for (int i = 2; i <= limit; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
		}
	}
	return primes;
}

vector<int> getFactorMoves(int x, const vector<int>& primes) {
	vector<pair<int, int>> factors;
	int tmp = x;

	for (int p : primes) {
		if (1LL * p * p > tmp) {
			break;
		}
		if (tmp % p != 0) {
			continue;
		}
		int cnt = 0;
		while (tmp % p == 0) {
			tmp /= p;
			cnt++;
		}
		factors.push_back({p, cnt});
	}
	if (tmp > 1) {
		factors.push_back({tmp, 1});
	}

	vector<int> divisors;
	function<void(int, int)> gen = [&](int idx, int cur) {
		if (idx == (int)factors.size()) {
			divisors.push_back(cur);
			return;
		}
		int p = factors[idx].first;
		int e = factors[idx].second;
		int val = 1;
		for (int i = 0; i <= e; i++) {
			gen(idx + 1, cur * val);
			val *= p;
		}
	};
	gen(0, 1);

	vector<int> nextVals;
	nextVals.reserve(divisors.size());
	for (int d : divisors) {
		if (d <= 1) {
			continue;
		}
		if (1LL * d * d > x) {
			continue;
		}
		nextVals.push_back(x / d);
	}

	sort(nextVals.begin(), nextVals.end());
	nextVals.erase(unique(nextVals.begin(), nextVals.end()), nextVals.end());
	return nextVals;
}

int minOperationsToOne(int n, const vector<int>& primes) {
	if (n == 1) {
		return 0;
	}

	unordered_map<int, int> dist;
	dist.reserve(8192);

	queue<int> q;
	q.push(n);
	dist[n] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int curDist = dist[x];

		int dec = x - 1;
		if (!dist.count(dec)) {
			dist[dec] = curDist + 1;
			if (dec == 1) {
				return dist[dec];
			}
			q.push(dec);
		}

		vector<int> factorMoves = getFactorMoves(x, primes);
		for (int y : factorMoves) {
			if (dist.count(y)) {
				continue;
			}
			dist[y] = curDist + 1;
			if (y == 1) {
				return dist[y];
			}
			q.push(y);
		}
	}

	return -1;
}

int main() {
	int T;
	cin >> T;

	const int LIM = 31623;
	vector<int> primes = buildPrimes(LIM);

	while (T--) {
		int n;
		cin >> n;
		cout << minOperationsToOne(n, primes) << '\n';
	}

	return 0;
}

