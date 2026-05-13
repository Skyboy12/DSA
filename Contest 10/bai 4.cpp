#include <bits/stdc++.h>

using namespace std;

string next_trinary(string current) {
    int n = current.size();
    for (int i = n - 1; i >= 0; --i) {
        if (current[i] == '0') {
            current[i] = '1';
            for (int j = i + 1; j < n; ++j) {
                current[j] = '0';
            }
            return current;
        } else if (current[i] == '1') {
            current[i] = '2';
            for (int j = i + 1; j < n; ++j) {
                current[j] = '0';
            }
            return current;
        }
    }
    return "1" + string(n, '0');
}

bool is_mostly_two(string s) {
    int count_2 = count(s.begin(), s.end(), '2');
    return count_2 > s.size() / 2;
}

int main(){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string current = "";
        for (int i = 0; i < n; ++i) {
            while (true) {
                current = next_trinary(current);
                if (is_mostly_two(current)) {
                    cout << current << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}