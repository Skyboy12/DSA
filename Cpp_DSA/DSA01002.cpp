#include <bits/stdc++.h>

using namespace std;

void next_list(vector<int>&list, int MAX, int LENGTH){
    int i = LENGTH - 1;
    while (i >= 0 && list[i] == MAX - LENGTH + i + 1) {
        i--;
    }
    if (i >= 0) {
        list[i]++;
        for (int j = i + 1; j < LENGTH; j++) {
            list[j] = list[j - 1] + 1;
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> list(k);
        for (auto&x : list){
            cin >> x;
        }
        next_list(list, n, k);
        for (auto x : list){
            cout << x << " ";
        }
        cout << endl;
    }
}