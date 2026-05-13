#include <bits/stdc++.h>

using namespace std;

vector<string> name_list_all;

vector<string> name_combination;

void dim_repeat(){
    vector<string> temp;
    temp.push_back(name_list_all[0]);
    for (int i = 1; i < name_list_all.size(); i++){
        if (name_list_all[i] != name_list_all[i - 1]){
            temp.push_back(name_list_all[i]);
        }
    }
    name_list_all = temp;
}

void Solution(int n, int k, int last_index = 0){
    if(name_combination.size() == k){
        for (auto &name : name_combination) cout << name << " ";
        cout << "\n";
        return;
    }
    for (int i = last_index; i < name_list_all.size(); i++){
        name_combination.push_back(name_list_all[i]);
        Solution(n, k, i + 1);
        name_combination.pop_back();
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    name_list_all.resize(n);
    for (auto &name : name_list_all) cin >> name;
    sort(name_list_all.begin(), name_list_all.end());
    dim_repeat();
    Solution(n, k);
    return 0;
}