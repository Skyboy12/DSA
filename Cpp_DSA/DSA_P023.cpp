#include <bits/stdc++.h>

using namespace std;

const int MAX = 19e4;

bool is_prime[MAX];

void sieve(){
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < MAX; i++){
        is_prime[i] = true;
    }
    for (int i = 2; i * i < MAX; i++){
        if (is_prime[i]){
            for (int j = i * i; j < MAX; j += i){
                is_prime[j] = false;
            }
        }
    }
}

int arr[25];

void printarr(int n){
    for (int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int cnt = 0;
void gen(int n, int k, int index){
    if(index > k){
        cnt++;
        if (is_prime[cnt]){
            cout << cnt << ": ";
            printarr(k);
        }
        return;
    }
    for (int i = arr[index - 1] + 1; i + (k - index) <= n; i++){
        arr[index] = i;
        gen(n, k, index + 1);
    }
}

int main(){
    int n, k; cin >> n >> k;
    sieve();
    arr[0] = 0;
    gen(n, k, 1);
    return 0;
}