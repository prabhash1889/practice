#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n + 1;
        for (char x = 'a'; x <= 'z'; x++)
        {
            int l = 0, r = n - 1;
            int res = 0;
            while (l < r)
            {
                if (s[l] == s[r])
                {
                    l++;
                    r--;
                }
                else if (s[l] == x)
                {
                    l++;
                    res++;
                }
                else if (s[r] == x)
                {
                    r--;
                    res++;
                }
                else
                {
                    res = n + 1;
                    break;
                }
            }
            ans = min(ans, res);
        }
        if (ans == n + 1)
        {
            ans = -1;
        }
        cout << ans << '\n';
    }
}