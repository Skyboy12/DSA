#include <bits/stdc++.h>

using namespace std;

vector<int> value_list = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

vector<int> money_count(100001, 9999999);

void Generate(){
    money_count[0] = 0;
    for (int i = 0; i < 100000; i++){
        if (money_count[i] == 9999999) continue;
        for (auto x : value_list){
            if (i + x <= 100000){
                money_count[i + x] = min(money_count[i + x], money_count[i] + 1);
            }
        }
    }
}


int main(){
    int t; cin >> t;
    Generate();
    while(t--){
        int n; cin >> n;
        cout << money_count[n] << endl;
    }
}