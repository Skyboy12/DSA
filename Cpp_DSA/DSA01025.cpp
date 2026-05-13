#include <bits/stdc++.h>
using namespace std;

string combination;

void Solution(int n, int k, int last_index = 0){
    if(combination.size() == k){
        cout << combination << "\n";
        return;
    }
    for (int i = last_index; i < n; i++){
        combination.push_back('A' + i);
        Solution(n, k, i + 1);
        combination.pop_back();
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        Solution(n, k);
    }
    return 0;
}