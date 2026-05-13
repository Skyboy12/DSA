#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int lt(int x, int y){
    if (y == 1) return x;
    long long last_ans = lt(x, y/2) %MOD;
    if (y%2==0){
        return last_ans*last_ans%MOD;
    } else return ((last_ans*last_ans)%MOD*x)%MOD;
}

int main(){
    int n, k; cin >> n >> k;
    while(n != 0  and k != 0){
        cout << lt(n,k) << endl;
        cin >> n >> k;
    }
    return 0;
}