#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[35];

bool is_fibo[10000];

void sieve(){
    for (int i = 0; i < 10000; i++){
        is_fibo[i] = false;
    }
    int a, b, c; a = 0; b = 1;
    while (c < 10000){
        c = a + b;
        a = b; 
        b = c;
        is_fibo[c] = true;
    }
}

void gen(){
    int tong = 0;
    for (int i = 1; i <= k; i++){
        arr[i] = i;
        tong += i;
    }
    bool in = false;
    while (!in){
        if (is_fibo[tong]){
            for (int i = 1; i <= k; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        int i = k;
        while (i > 0 && arr[i] == n - k + i){
            i--;
        }
        if (i == 0){
            in = true;
        } else {
            arr[i]++;
            tong++;
            for (int j =  i + 1; j <= k; j++){
                int temp = arr[j];
                arr[j] = arr[j - 1] + 1;
                tong = tong - temp + arr[j];
            }
        }
    }
}
int main(){
    sieve();
    cin >> n >> k;
    gen();
    return 0;
}