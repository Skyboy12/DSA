#include <bits/stdc++.h>

using namespace std;

void printout(vector<int> list){
    cout << '[';
    int last = list.back(); list.pop_back();
    for (auto x : list) cout << x << ' ';
    cout << last << ']' << endl;
}
void Solution(vector<int> list){
    int length = list.size();
    while(length--){
        printout(list);
        vector<int> newlist;
        for (int i = 0; i < list.size() - 1; i++){
            newlist.push_back(list[i] + list[i+1]);
        }
        list = newlist;
    }
    return;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> list(n);
        for (auto & x : list) cin >> x;
        Solution(list);
    }
    return 0;
}