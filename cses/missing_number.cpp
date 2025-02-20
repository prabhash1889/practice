#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxN = 2e5;
ll n, p[mxN];

void solve(int tc = 0)
{
    int64_t n;
    cin >> n;
    // vector<int64_t> a(n - 1);
    // for (auto &x : a)
    //     cin >> x;
    // sort(a.begin(), a.end());
    // for (int64_t i = 1; i < n; i++)
    // {
    //     if (a[i - 1] != i)
    //     {
    //         cout << i << '\n';
    //         return;
    //     }
    // }
    int64_t sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    int64_t true_s = n * 1ll * (n + 1) / 2;
    int64_t ans = true_s - sum;
    cout << ans << '\n';
}

int main()
{

    int tc = 1;
    // cin>>tc;
    for (int t = 0; t < tc; t++)
        solve(t);
}