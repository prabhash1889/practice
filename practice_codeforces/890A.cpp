#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a[6];
    for (int i = 0; i < 6; i++)
    {
        std::cin >> a[i];
    }

    for (int s = 0; s < (1 << 6); s++)
    {
        if (__builtin_popcount(s) == 3)
        {
            int bal = 0;
            for (int i = 0; i < 6; i++)
            {
                if (s >> i & 1)
                {
                    bal += a[i];
                }
                else
                {
                    bal -= a[i];
                }
            }
            if (bal == 0)
            {
                std::cout << "YES\n";
                return 0;
            }
        }
    }
    std::cout << "NO\n";

    return 0;
}