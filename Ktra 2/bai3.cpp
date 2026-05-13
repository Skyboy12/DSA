#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return st.empty();
}
int countValid(string s)
{
    int count = 0;
    for (char c : s)
    {
        if (c == '[')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string s;
    cin >> s;
    int maxValidCount = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j <= s.size(); j++)
        {
            string substring = s.substr(i, j - i);
            if (isValid(substring))
            {
                int validCount = countValid(substring);
                maxValidCount = max(maxValidCount, validCount);
            }
        }
    }
    cout << maxValidCount << endl;
}