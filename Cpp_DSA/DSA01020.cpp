#include <bits/stdc++.h>

using namespace std;

string Binary;

void reverseBinaryFlipFlop(string& Binary) {
    int n = Binary.length();
    for (int i = n - 1; i >= 0; i--) {
        if (Binary[i] == '1') {
            Binary[i] = '0';
            for (int j = i + 1; j < n; j++) {
                Binary[j] = '1';
            }
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        Binary[i] = '1';
    }
}

int main(){
    int t; 
    cin >> t;
    while(t--){
        string Binary;
        cin >> Binary;
        reverseBinaryFlipFlop(Binary);
        cout << Binary << endl;
    }
    return 0;
}