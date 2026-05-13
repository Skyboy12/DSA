#include <bits/stdc++.h>

using namespace std;

int S2T(int S, int T){
    if (S == T) return 0;
    
    queue<pair<int, int>> q; 
    unordered_set<int> visited;
    
    q.push({S, 0});
    visited.insert(S);
    
    while (!q.empty()) {
        auto [num, steps] = q.front();
        q.pop();
        
        if (num == T) return steps;
        
        if (num - 1 > 0 && visited.find(num - 1) == visited.end()) {
            visited.insert(num - 1);
            q.push({num - 1, steps + 1});
        }
        
        if (num * 2 <= 20000 && visited.find(num * 2) == visited.end()) {
            visited.insert(num * 2);
            q.push({num * 2, steps + 1});
        }
    }
    
    return -1;
}

int main(){
    int t; cin >> t;
    while (t--) {
        int S, T; cin >> S >> T;
        cout << S2T(S, T) << endl;
    }
    return 0;
}