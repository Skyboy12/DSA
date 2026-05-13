#include <bits/stdc++.h>

using namespace std;

struct Sum{
    vector<int> index_list;
    long long sum = 0;
    Sum(void) : sum(0){
        index_list.clear();
    }
};

bool cmp(Sum a, Sum b){
    if (a.sum != b.sum) return a.sum < b.sum;
    return a.index_list < b.index_list;
}

vector<Sum> Sumlist;
Sum current;
void Solution(vector<int> list, int n, int k){
    if (current.sum > k || (current.index_list.size() > 0 && current.index_list.back() == n - 1)) {
        if (current.sum != 0 && current.sum <= k) {
            Sumlist.push_back(current);
        }
        return;
    }
    if (current.sum != 0 && current.sum <= k) {
        Sumlist.push_back(current);
    }
    int i = 0;
    if (current.index_list.size() != 0) i = current.index_list.back() + 1;
    for (; i < n; i++) {
        current.index_list.push_back(i);
        current.sum += list[i];
        Solution(list, n, k);
        current.index_list.pop_back();
        current.sum -= list[i];
    }
}

int main(){
    int n, k; cin >> n >> k;
    vector<int> list(n);
    for (auto & x : list) cin >> x;
    Solution(list, n, k);
    if (Sumlist.size() == 0){
        cout << -1;
        return 0;
    }
    sort(Sumlist.begin(), Sumlist.end(), cmp);
    for (auto sum : Sumlist){
        for (auto x : sum.index_list) cout << x + 1 << ' ';
        cout << endl <<"Sum = " << sum.sum << endl;
    }
    return 0;
}