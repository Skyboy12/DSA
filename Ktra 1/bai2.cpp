#include <bits/stdc++.h>

using namespace std;

int sod(long long n){
    int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long find_x(long long n, int s){
    long long org_n = n;
    long long p = 10;
    while (sod(n) > s){
        long long rem = n % p;
        if (rem > 0){
            n += (p - rem);
        }
        p *= 10;
    }
    return n - org_n;
}

int main(){
    int t; cin >> t;
    while (t--){
        long long n; int s; cin >> n >> s;
        cout << find_x(n, s) << endl;
    }
}