#include <bits/stdc++.h>

using namespace std;

bool validDigit[10];
vector<int> result;
void generate(int n, int current)
{
    if (current == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << result[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (validDigit[i])
        {
            result.push_back(i);
            generate(n, current + 1);
            result.pop_back();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++)
    {
        validDigit[i] = false;
    }
    for (int i = 0; i < 3; i++)
    {
        int x;
        cin >> x;
        validDigit[x] = true;
    }
    generate(n, 0);
}