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
        int a, b, c;
        cin >> a >> b >> c;
        int tt = abs(a - b);
        int ans = (tt + 2 * c - 1) / (2 * c);
        cout << ans << '\n';
    }
}