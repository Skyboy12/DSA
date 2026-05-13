#include <bits/stdc++.h>

using namespace std;

string next_binary(string current) {
    int n = current.size();
    for (int i = n - 1; i >= 0; --i) {
        if (current[i] == '0') {
            current[i] = '1';
            for (int j = i + 1; j < n; ++j) {
                current[j] = '0';
            }
            return current;
        }
    }
    return "1" + string(n, '0');
}

int main(){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string current = "0";
        for (int i = 0; i < n; ++i) {
            current = next_binary(current);
            cout << current << " ";
        }
        cout << endl;
    }
    return 0;
}