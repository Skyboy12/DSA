#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}
int c;
int arr[25];

void Try(int n, int k, int cr_i){
    if (cr_i == k){
        c++;
        if (is_prime(c)){
            cout << c << ": ";
            for (int i = 1; i <= k; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for(int i = arr[cr_i] + 1; i <= n; i++){
        arr[cr_i + 1] = i;
        Try(n, k, cr_i + 1);
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    arr[0] = 0;
    Try(n, k, 0);
    return 0;
}