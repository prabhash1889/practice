#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxN = 2e5;
ll n, p[mxN];

void solve(int tc = 0)
{
    // long long r, c;
    // cin >> r >> c;

    // if (r >= c)
    // {
    //     if (r % 2 == 1)
    //         cout << r * 1ll * r - (c - 1) << endl;
    //     else
    //         cout << (r - 1) * 1ll * (r - 1) + c << endl;
    // }
    // else
    // {
    //     if (c % 2 == 1)
    //         cout << (c - 1) * 1ll * (c - 1) + r << endl;
    //     else
    //         cout << c * 1ll * c - (r - 1) << endl;
    // }
    ll y, x;
    cin >> y >> x;
    ll z = max(y, x);
    ll z2 = (z - 1) * 1LL * (z - 1);
    ll ans;
    if (z % 2)
    {
        if (y == z)
        {
            ans = z2 + x;
        }
        else
        {
            ans = z2 + 2 * z - y;
        }
    }
    else
    {
        if (x == z)
        {
            ans = z2 + y;
        }
        else
        {
            ans = z2 + 2 * z - x;
        }
    }
    cout << ans << '\n';
}

int main()
{

    int tc = 1;
    cin >> tc;
    for (int t = 0; t < tc; t++)
        solve(t);
}