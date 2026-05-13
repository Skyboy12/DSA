#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9 + 7;
struct Matrix
{
    vector<vector<long long>> mat;
    int size;
    Matrix(int n) : size(n) {
        mat.resize(n, vector<long long>(n, 0));
    }
    static Matrix identity(int n){
        Matrix res(n);
        for (int i = 0; i < n; i++) res.mat[i][i] = 1;
        return res;
    }
    Matrix operator* (const Matrix&res){
        Matrix ans(size);
        for(int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                for (int k = 0; k < size; k++){
                    ans.mat[i][j] = (ans.mat[i][j] + mat[i][k]*res.mat[k][j]) % MOD;
                }
            } 
        }
        return ans;
    }
};

Matrix power(Matrix a, long long b){
        Matrix ans = Matrix::identity(a.size);
        while (b > 0){
            if (b % 2 == 1) ans = ans * a;
            a = a * a;
            b /=2;
        }
        return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        Matrix a(n);
        for (auto & row : a.mat){
            for (auto & ele : row) cin >> ele;
        }
        Matrix apow = power(a, k);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + apow.mat[i][n - 1 - i]) % MOD;
        }
        cout << ans << endl;
    }
}
