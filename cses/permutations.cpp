#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxN = 2e5;
ll n, p[mxN];

void solve(int tc = 0)
{
    int64_t n;
    cin >> n;
    if (n < 4 and n != 1)
    {
        cout << "NO SOLUTION" << '\n';
        return;
    }
    vector<int> v;
    for (int i = 1; i <= n / 2; i++)
    {
        v.push_back(2 * i * 1ll);
    }
    for (int i = 0; i <= n / 2; i++)
    {
        v.push_back(2 * i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{

    int tc = 1;
    // cin>>tc;
    for (int t = 0; t < tc; t++)
        solve(t);
}