#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        vector<long long> dp_increase(n);
        vector<long long> dp_decrease(n);
        for (int i = 0; i < n; i++) {
            dp_increase[i] = 0;
            dp_decrease[i] = 0;
        }
        long long max_total_length_from_one_element = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    dp_increase[i] = max(dp_increase[i], dp_increase[j] + 1);
                }
                if (a[i] < a[j]) {
                    dp_decrease[i] = max(dp_decrease[i], dp_decrease[j] + 1);
                }
            }
            max_sum = max(max_sum, max(dp_increase[i], dp_decrease[i]));
        }

    }
}