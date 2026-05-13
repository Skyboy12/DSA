#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for (auto & x : a) cin >> x;
    int p1, p2; p1 = p2 = 0;
    while (a.size() > 0){
        int add_number;
        if (a.front() > a.back()){
            add_number = a.front();
            a.erase(a.begin());
        } else {
            add_number = a.back();
            a.pop_back();
        }
        p1 += add_number;
        if (a.size() == 0) break;
        if (a.front() > a.back()){
            add_number = a.front();
            a.erase(a.begin());
        } else {
            add_number = a.back();
            a.pop_back();
        }
        p2 += add_number;
    }
    cout << p1 << " " << p2 << endl;
}