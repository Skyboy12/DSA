#include <bits/stdc++.h>

using namespace std;

vector<bool> used;
vector<int> nums;

void Solution(int n){
    int length = nums.size();
    if(length == n){
        for (auto x : nums){
            cout << x;
        }
        cout << " ";
        return;
    }
    for (int i = n; i >0; i--){
        if (!used[i-1]){
            used[i-1] = true;
            nums.push_back(i);
            Solution(n);
            nums.pop_back();
            used[i-1] = false;
        }
    }
}

void reset(int n){
    used.empty();
    while(n--) used.push_back(false);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        reset(n);
        Solution(n);
        cout << endl;
    }
    return 0;
}