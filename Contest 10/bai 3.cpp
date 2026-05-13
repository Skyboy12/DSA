#include <bits/stdc++.h>

using namespace std;

string next_4_5(string current) {
    int n = current.size();
    for (int i = n - 1; i >= 0; --i) {
        if (current[i] == '4') {
            current[i] = '5';
            for (int j = i + 1; j < n; ++j) {
                current[j] = '4';
            }
            return current;
        }
    }
    return "4" + string(n, '4');
}

string reverse_string(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string current = "";
        for (int i = 0; i < n; ++i) {
            current = next_4_5(current);
            cout << current+reverse_string(current) << " ";
        }
        cout << endl;
    }
}

