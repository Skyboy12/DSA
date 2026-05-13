#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);
    int maxDiff = 0;
    for (int i = 1; i < n; i++)
    {
        vector<int> charCount(26, 0);
        bool isUsed[26] = {false};
        for (int j = 0; j < i; j++)
        {
            charCount[s[j] - 'a']++;
            if (!isUsed[s[j] - 'a'])
            {
                isUsed[s[j] - 'a'] = true;
            }
        }
        int minCount = n;
        int maxCount = 0;
        for (int j = 0; j < 26; j++)
        {
            if (isUsed[j])
            {
                minCount = min(minCount, charCount[j]);
                maxCount = max(maxCount, charCount[j]);
            }
        }
        int diff = maxCount - minCount;
        maxDiff = max(maxDiff, diff);
        for (int j = i + 1; j < n; j++)
        {
            charCount[s[j] - 'a']++;
            if (!isUsed[s[j] - 'a'])
            {
                isUsed[s[j] - 'a'] = true;
            }
            charCount[s[j - i - 1] - 'a']--;
            if (charCount[s[j - i - 1] - 'a'] == 0)
            {
                isUsed[s[j - i - 1] - 'a'] = false;
            }
            minCount = n;
            maxCount = 0;
            for (int k = 0; k < 26; k++)
            {
                if (isUsed[k])
                {
                    minCount = min(minCount, charCount[k]);
                    maxCount = max(maxCount, charCount[k]);
                }
            }
            diff = maxCount - minCount;
            maxDiff = max(maxDiff, diff);
        }
    }
    cout << maxDiff << endl;
}