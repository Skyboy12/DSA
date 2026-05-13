#include <bits/stdc++.h>

using namespace std;

vector<int> alist;

void Solution(int n, int m, vector<bool> & is_used){
    if (alist.size() == n - 1){
        alist.push_back(m);
        for (auto x : alist) cout << x << " ";
        alist.pop_back();
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!(is_used[i-1] || i == m)){
            is_used[i-1] = true;
            alist.push_back(i);
            Solution(n, m, is_used);
            alist.pop_back();
            is_used[i-1] = false;
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<bool> is_used(n, false);
    Solution(n, m, is_used);
    return 0;
}