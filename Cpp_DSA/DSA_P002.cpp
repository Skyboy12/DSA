#include <bits/stdc++.h>

using namespace std;

int arr[10];
bool used[11];

void printout(int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void generator(int n, int k){
    static int count = 1;
    if (k == n){
        cout << count++ << ": ";
        printout(n);
    }
    for (int i = 1; i <= n; i++){
        if (!used[i]){
                arr[k] = i; 
                used[i] = true;
                generator(n, k+1);
                used[i] = false;
        }
    }
}

int main(){
    int n; cin >> n;
    for (int i = 0; i <= n; i++){
        used[i] = false;
    }
    generator(n, 0);
    return 0;
}