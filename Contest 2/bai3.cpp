#include <bits/stdc++.h>

using namespace std;

int B[200];
int n;
int OK;
int ca, cb;
void in(){
    for(int i = 1; i <= n; i++) {
        if (B[i]) cout <<"B";
        else cout <<"A";
    }
    cout << endl;
}
void sinh(){
    int i = n;
    while(B[i]){
        B[i] = 0; i--; ca++; cb--;
    }
    if (i == 0) OK = 1;
    else {
        B[i] = 1;
        ca--; cb++;
    }
}
int main(){
    cin >> n;
    ca = n; cb = 0;
    while (!OK){
        if (ca && cb) in();
        sinh();
    }
}