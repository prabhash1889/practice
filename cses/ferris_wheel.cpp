#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxN = 2e5;
ll n, p[mxN];

void solve(int tc = 0)
{
    int n, x;
    cin >> n >> x;
    vector<int> C(n);
    for (auto c : C)
        cin >> c;
    sort(C.begin(), C.end());
    int i = 0, j = n - 1;
    int ans = 0;
    while (i <= j)
    {
        if (C[j] + C[i] <= x)
        {
            ans++;
            j--;
            i++;
        }
        else
        {
            ans++;
            j--;
        }
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