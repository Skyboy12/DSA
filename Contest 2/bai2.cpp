#include <bits/stdc++.h>

using namespace std;

int B[200];
int n;
int OK;
void in(){
    for(int i = 1; i <= n; i++) cout << B[i];
    cout << endl;
}
void sinh(){
    int i = n;
    while(B[i]){
        B[i] = 0; i--;
    }
    if (i == 0) OK = 1;
    else B[i] = 1;
}
int main(){
    cin >> n;
    int k; cin >> k;
    while (!OK){
        in();
        for(int i = 0; i < k && !OK; i++) sinh();
    }
}