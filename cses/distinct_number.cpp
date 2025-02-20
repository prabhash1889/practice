#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxN = 2e5;
ll n, p[mxN];

void solve(int tc = 0)
{
    int n;
    cin >> n;
    set<int> S;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        S.insert(x);
        // cin >> S[i];
    }
    cout << S.size() << '\n';
}

int main()
{

    int tc = 1;
    // cin>>tc;
    for (int t = 0; t < tc; t++)
        solve(t);
}