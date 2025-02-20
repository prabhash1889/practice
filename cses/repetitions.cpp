#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxN = 2e5;
ll n, p[mxN];

void solve(int tc = 0)
{
    string s;
    cin >> s;
    int ans = 1, c = 0;
    char l = 'A';
    for (char ch : s)
    {
        if (ch == l)
        {
            ++c;
            ans = max(c, ans);
        }
        else
        {
            l = ch;
            c = 1;
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