#include <bits/stdc++.h>

using namespace std;

void inOrder(vector<int> &a, int i)
{
    if (i >= a.size())
        return;
    inOrder(a, 2 * i + 1);
    cout << a[i] << " ";
    inOrder(a, 2 * i + 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        inOrder(a, 0);
        cout << endl;
    }
}