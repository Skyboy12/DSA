#include <bits/stdc++.h>

using namespace std;

int main(){
    long long input, max;
    max = 0;
    while (cin >> input){
        if (input > max) {max = input;}
    }
    cout << max;
}