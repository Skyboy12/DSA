#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> current_per(n);
        for (auto &x : current_per) cin >> x;
        int count = 1;
        while (prev_permutation(current_per.begin(), current_per.end())) {
            count++;
        }
        cout << count << endl;
    }
    return 0;
}