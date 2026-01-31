#include <bits/stdc++.h>

using namespace std;

int B[200];
int n;
int OK;
int c;
void in(){
    for(int i = 1; i <= n; i++) cout << B[i] <<" ";
    cout << endl;
}
void sinh(){
    int i = n;
    while(B[i]){
        B[i] = 0; i--;
        c--;
    }
    if (i == 0) OK = 1;
    else {
        B[i] = 1; c++;
    }
}
int main(){
    cin >> n;
    c = 0;
    while (!OK){
        if (c%2 ==0) in();
        sinh();
    }
}