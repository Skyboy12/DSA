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
    c++;
    int i = n;
    while(B[i]){
        B[i] = 0; i--;
    }
    if (i == 0) OK = 1;
    else {
        B[i] = 1; 
    }
}
int main(){
    cin >> n;
    c = 1;
    long long fibo[92];
    fibo[0]=1; fibo[1]=1;
    for (int i = 2; i < 30; i++) fibo[i] = fibo[i-1] +fibo[i-2]; 
    for (int i = 1; i < 30 && !OK; i++){
        while(!OK && c < fibo[i]) sinh();
        if (c == fibo[i]){
            cout << c << ": ";
            in();
        }
    }
}