#include <bits/stdc++.h>

using namespace std;

long long MandC(vector<long long>& a, vector<long long>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inversions = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= right) {
        temp[k++] = a[j++];
    }

    for (int idx = left; idx <= right; ++idx) {
        a[idx] = temp[idx];
    }

    return inversions;
}

long long MSandC(vector<long long>& a, vector<long long>& temp, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    long long inversions = 0;

    inversions += MSandC(a, temp, left, mid);
    inversions += MSandC(a, temp, mid + 1, right);
    inversions += MandC(a, temp, left, mid, right);

    return inversions;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n), temp(n);
        for (auto& x : a){
            cin >> x;
        }

        cout << MSandC(a, temp, 0, n - 1) << '\n';
    }
    return 0;
}