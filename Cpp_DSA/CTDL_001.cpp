#include <bits/stdc++.h>

using namespace std;

int bit[20];
void printbit(int n, bool c){
    for (int i = 0; i < n; i++){
        cout << bit[i] << " ";
    }
    if (c){
        cout << bit[n - 1] << " ";
    }
    for (int i = n - 2; i >= 0; i--){
        cout << bit[i] << " ";
    }
    cout << endl;
}

void generator(int n, int k, bool c){
    if (k == n){
        printbit(n, c);
        return;
    }
    for (int i = 0; i < 2 ; i++){
        bit[k] = i;
        generator(n, k + 1, c);
    }
}

int main(){
    int N; cin >> N;
    generator((int)(N/2), 0, (N%2)==0); 
    return 0;
}