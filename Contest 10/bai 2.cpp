#include <bits/stdc++.h>

using namespace std;


long long findSmallestBDN(long long n) {
    queue<long long> q;
    q.push(1);
    
    while (!q.empty()) {
        long long num = q.front();
        q.pop();
        
        if (num % n == 0) {
            return num;
        }
        
        q.push(num * 10);
        q.push(num * 10 + 1);
    }
    return -1;
}

int main(){
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        cout << findSmallestBDN(n) << endl;
    }
    return 0;
}