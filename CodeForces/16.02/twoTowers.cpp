#include <bits/stdc++.h>
using namespace std;

bool canBeBeautiful(string s1, string s2, int n, int m)
{
    reverse(s2.begin(), s2.end());
    int len = n + m - 1;
    s1 += s2;
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (s1[i] == s1[i + 1])
        {
            cnt++;
        }
    }
    if (cnt <= 1)
    {
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;

        string s1, s2;
        cin >> s1 >> s2;

        if (canBeBeautiful(s1, s2, a, b))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}