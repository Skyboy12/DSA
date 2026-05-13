#include <bits/stdc++.h>

using namespace std;

string str;

void Solution(int n){
    if (str.length() == n){
        cout << str << " ";
        return;
    }
    str.push_back('A');
    Solution(n);
    str.pop_back();
    str.push_back('B');
    Solution(n);
    str.pop_back();
}


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        Solution(n);
        cout << endl;
    }
    return 0;
}