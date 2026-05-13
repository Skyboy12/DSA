#include <bits/stdc++.h>

using namespace std;

vector<bool> used;
vector<int> a;

void solution(int n, int curr_dif){
    int size = a.size();
    if (size == n){
        if (curr_dif > 0){
            for (auto x : a){
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }
    if (size == 0){
        for (int i = 1; i <= n; i++){
            used[i-1] = true;
            a.push_back(i);
            solution(n, 0);
            a.pop_back();
            used[i-1] = false;
        }
    } else {
        for (int i = 1; i <= n; i++){
            if (!used[i-1]){
                used[i-1] = true;
                int dif = a.back() - i;
                a.push_back(i);
                solution(n, curr_dif + dif);
                a.pop_back();
                used[i-1] = false;
            }
        }
    }
}

int main(){
    int n; cin >> n;
    used.resize(n, false);
    solution(n, 0);
    return 0;
}