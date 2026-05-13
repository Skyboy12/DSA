#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    string leftPart, rightPart;
    leftPart.reserve(s.size());
    rightPart.reserve(s.size());

    for (char c : s) {
        if (c == '<') {
            if (!leftPart.empty()) {
                rightPart.push_back(leftPart.back());
                leftPart.pop_back();
            }
        } else if (c == '>') {
            if (!rightPart.empty()) {
                leftPart.push_back(rightPart.back());
                rightPart.pop_back();
            }
        } else if (c == '-') {
            if (!leftPart.empty()) {
                leftPart.pop_back();
            }
        } else {
            leftPart.push_back(c);
        }
    }

    reverse(rightPart.begin(), rightPart.end());
    cout << leftPart << rightPart << '\n';
    return 0;
}
