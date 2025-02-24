#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int j = 0; j < n; j++)
            cin >> b[j];

        // vector<pair<int, int>> vp;
        // for (int i = 0; i < n; i++)
        // {
        //     vp.push_back({a[i], b[i]});
        // }
        // sort(vp.begin(), vp.end());

        // int i = 0;
        // while (vp[i].first <= k)
        // {
        //     k += vp[i].second;
        //     i++;
        // }
        // cout << k << '\n';
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int i, int j)
             { return a[i] < a[j]; });
        for (auto i : p)
        {
            if (a[i] <= k)
                k += b[i];
        }
        cout << k << '\n';
    }
}