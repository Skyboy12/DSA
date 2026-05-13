#include <iostream>
using namespace std;

void inorder(int i, int n, int A[]) {
    if (i < n) {
        inorder(2 * i + 1, n, A);
        cout << A[i] << " ";
        inorder(2 * i + 2, n, A);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[10005];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        inorder(0, n, A);
        cout << endl;
    }
    return 0;
}
