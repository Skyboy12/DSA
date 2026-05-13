#include <bits/stdc++.h>

using namespace std;

void flipflop(string& bin_str, int index = -1){
    if (index == -1) index = bin_str.length() - 1;
    if (index < 0) return;
    
    if (bin_str[index] == '0') {
        bin_str[index] = '1';
    } else {
        bin_str[index] = '0';
        flipflop(bin_str, index - 1);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        string bin_str;
        cin >> bin_str;
        flipflop(bin_str, bin_str.length() - 1);
        cout << bin_str << endl;
    }
}