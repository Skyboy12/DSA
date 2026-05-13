#include <bits/stdc++.h>

using namespace std;

int n;
int a[20];

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        if (i == 1 && j == 0) continue;
        if (i > 1 && a[i - 1] == 1 && j == 1) continue;
        if (i == n && j == 1) continue;
        
        a[i] = j;
        if (i == n) {
            for (int k = 1; k <= n; k++) {
                if (a[k] == 1) cout << "H";
                else cout << "A";
            }
            cout << endl;
        } else {
            Try(i + 1);
        }
    }
}

int main(){
    int t; 
    cin >> t;
    while(t--){
        cin >> n;
        Try(1);
    }
    return 0;
}