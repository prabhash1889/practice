#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += (180 - a[i]);
    }
    cout << ans / 2 << '\n';
}