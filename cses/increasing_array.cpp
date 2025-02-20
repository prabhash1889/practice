#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxN = 2e5;
ll n, p[mxN];

void solve(int tc = 0)
{
    int n;
    cin >> n;
    //     vector<int64_t> num(n + 1);
    //     for (auto x : num)
    //         cin >> x;
    //     int64_t ans = 0;
    //     for (int i = 1; i < n; i++)
    //     {
    //         if (num[i] > num[i - 1])
    //         {
    //             ans += 1ll * (num[i - 1] - num[i]);
    //             num[i] += (num[i - 1] - num[i]);
    //         }
    //     }
    //     cout << ans << '\n';
    int64_t mx = 0;
    int64_t ans = 0;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t x;
        cin >> x;
        mx = max(mx, x);
        ans += mx - x;
    }
    cout << ans << '\n';
}

int main()
{

    int tc = 1;
    // cin>>tc;
    for (int t = 0; t < tc; t++)
        solve(t);
}