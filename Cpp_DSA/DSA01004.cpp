#include <bits/stdc++.h>

using namespace std;

void Solution(vector<int>&list, int n, int k){
    int ls = list.size();
    if (ls == k){
        for (auto x : list) cout << x;
        cout << " ";
        return;
    }
    if (ls == 0){
        for (int i = 1; i <= n - k + 1; i++){
            list.push_back(i);
            Solution(list, n, k);
            list.pop_back();
        }
    } else {
        for (int i = list.back() + 1; i <= n - k + ls + 1; i++){
            list.push_back(i);
            Solution(list, n, k);
            list.pop_back();
        }
    }
}
int main(){
    vector<int> list;
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        Solution(list, n, k);
        cout << endl;
    }
    return 0;
}