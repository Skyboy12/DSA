#include <bits/stdc++.h>

using namespace std;

int arr[25];

void prtarr(int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void gentry(int n, int k, int index){
    if (index == -1){
        prtarr(k);
        return;
    }
    for (int i = arr[index+1] - 1; i > 0; i--){
        arr[index] = i;
        gentry(n, k, index - 1);
    }
}

int main(){
    int n, k; cin >> n >> k;
    arr[k-1] = n + 1;
    gentry(n, k, k-1);
    return 0;
}