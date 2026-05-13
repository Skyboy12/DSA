#include <bits/stdc++.h>

using namespace std;

struct Job {
    int start, end;
};

bool cmp(Job a, Job b) {
    if (a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        vector<Job> list(n);
        for (auto&x : list) {
            cin >> x.start >> x.end;
        }
        
        sort(list.begin(), list.end(), cmp);
        
        int count = 1;
        int current_end_time = list[0].end;
        
        for (int i = 1; i < n; i++) {
            if (list[i].start >= current_end_time) {
                count++;
                current_end_time = list[i].end;
            }
        }
        
        cout << count << endl;
    }
    return 0;
}