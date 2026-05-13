#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> target(k);
        for (auto &x : target) cin >> x;
        
        vector<int> current_list(k);
        for (int i = 0; i < k; i++) current_list[i] = i + 1;
        
        int count = 1;
        while (!check(current_list, target)) {
            int i = k - 1;
            while (i >= 0 && current_list[i] == n - k + i + 1) {
                i--;
            }
            if (i < 0) break;
            current_list[i]++;
            for (int j = i + 1; j < k; j++) {
                current_list[j] = current_list[j - 1] + 1;
            }
            count++;
        }
        cout << count << endl;
    }
    return 0;
}