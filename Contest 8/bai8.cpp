#include <bits/stdc++.h>

using namespace std;

int MAX = 1e6 + 1;

vector<int> total(MAX, 0);

void gen() {
    total[1] = 1;
    for(int i = 2; i < MAX; i++){
        total[i] = MAX;
        for(int j = 1; j * j <= i; j++){
            total[i] = min(total[i], total[i - j * j] + 1);
        }
    }
}

int main(){
    int t; cin >> t;
    gen();
    while(t--){
        int n; cin >> n;
        cout << total[n] << "\n";
    }
}