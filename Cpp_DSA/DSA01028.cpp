#include <bits/stdc++.h>

using namespace std;

vector<int> number_list;
vector<int> current_list;
int current_index = 0;
void Solution(int k){
    if (current_list.size() == k){
        for (auto x : current_list) cout << x << ' ';
        cout << endl;
        return;
    }
    for (int i = current_index; i < number_list.size(); i++){
        current_list.push_back(number_list[i]);
        current_index = i + 1;
        Solution(k);
        current_list.pop_back();
    }
}

int main(){
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if (find(number_list.begin(), number_list.end(), x) == number_list.end()){
            number_list.push_back(x);
        }
    }
    sort(number_list.begin(), number_list.end());
    Solution(k);
    return 0;
}