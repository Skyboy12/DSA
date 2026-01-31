#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, l;
    l = "";
    while(getline(cin, s)){
        stringstream iss(s);
        string token;
        while (iss >> token){
            if (token.length() > l.length()) l = token;
        }
    }
    cout << l << " - " << l.length();
    return 0;
}