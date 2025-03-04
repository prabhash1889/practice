#include <bits/stdc++.h>
using namespace std;

int lowbit(int x)
{
    return x & (-x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;
        int lb = lowbit(x);
        while (!(lb ^ x) || !(lb & x))
            lb++;
        cout << lb << '\n';
    }
}