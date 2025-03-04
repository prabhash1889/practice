#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int k = 1; k < 11; k++)
    {
        int t = ((1 << k) - 1) * (1 << (k - 1));
        if (n % t == 0)
            ans = t;
    }
    cout << ans;
}