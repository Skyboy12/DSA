#include <bits/stdc++.h>

using namespace std;

int counts=0;
vector<int> binary;

void Solution(int n, int k){
    int l = binary.size();
    if(l == n){
        if (counts == k){
            for (int i = 0; i < l; i++){
                cout << binary[i];
            }
            cout << endl;
        }
        return;
    }
    binary.push_back(0);
    Solution(n, k);
    binary.pop_back();
    counts++;
    binary.push_back(1);
    Solution(n, k);
    binary.pop_back();
    counts--;
}

int main(){
    int t; 
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        counts = 0;
        binary.clear();
        Solution(n, k);
    }
    return 0;
}