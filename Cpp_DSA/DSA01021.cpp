#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; 
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        set<int> st;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            st.insert(a[i]);
        }
        
        int i = k - 1;
        while (i >= 0 && a[i] == n - k + i + 1) {
            i--;
        }
        
        if (i < 0) {
            cout << k << endl;
        } else {
            a[i]++;
            for (int j = i + 1; j < k; j++) {
                a[j] = a[j - 1] + 1;
            }
            int cnt = 0;
            for (int j = 0; j < k; j++) {
                if (st.find(a[j]) == st.end()) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}