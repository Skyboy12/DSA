#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> *a = new vector<int>(n);
    for (auto &x : *a){
        cin >> x;
    }
    vector<vector<int>> dp;
    for (int i = 0; i < n; i++){
        vector<int> *curr = new vector<int>();
        curr->push_back((*a)[i]);
        for (int j = i + 1; j < n; j++){
            curr->push_back(min(curr->back(), (*a)[j]));
        }
        dp.push_back(*curr);
        delete curr;
    }
    delete a;
    for (int x = 1; x <= n; x++){
        int ans = 0;
        for (int i = 0; i <= n - x; i++){
            int min_val = dp[i][x - 1];
            ans = max(ans, min_val);
        }
        cout << ans << " ";
    }
    return 0;
}