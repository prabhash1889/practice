#include <bits/stdc++.h>
using namespace std;
// using i64 = long long;


int main()
{

    int n, m, k;
    cin >> n >> m >> k;

    std::vector<int> x(k), y(k);
    for (int i = 0; i < k; i++)
    {
        cin >> x[i] >> y[i];
    }

    int X = 1, Y = 1, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int d = 1E9;
            for (int l = 0; l < k; l++)
            {
                d = std::min(d, std::abs(i - x[l]) + std::abs(j - y[l]));
            }
            if (d > ans)
            {
                X = i;
                Y = j;
                ans = d;
            }
        }
    }
    cout << X << " " << Y << "\n";

    return 0;
}