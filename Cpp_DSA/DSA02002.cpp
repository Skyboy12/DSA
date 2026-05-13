#include <bits/stdc++.h>

using namespace std;

void printout(vector<int> list){
    cout << '[';
    for (int i = 0; i < list.size(); i++) {
        cout << list[i];
        if (i < list.size() - 1) cout << " ";
    }
    cout << "] ";
}
void Solution(vector<int> list){
    int length = list.size();
    vector<vector<int>> all_list;
    while(length--){
        all_list.insert(all_list.begin(), list);
        vector<int> newlist;
        for (int i = 0; i < list.size() - 1; i++){
            newlist.push_back(list[i] + list[i+1]);
        }
        list = newlist;
    }
    for (auto&x : all_list) printout(x);
    cout << endl;
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