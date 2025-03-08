#include <bits/stdc++.h>

using i64 = long long;
struct DSU
{
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
void solve()
{
    int n;
    std::cin >> n;

    int ans = 0;
    for (int l = n * n;; l--)
    {
        DSU dsu(n + 1);
        int sum = 0;
        bool ok = true;
        for (int i = n; i >= 1; i--)
        {
            int x = dsu.find(std::min(n, l / i));
            if (x == 0)
            {
                ok = false;
                break;
            }
            sum += i * x;
            dsu.merge(x - 1, x);
        }
        if (!ok)
        {
            break;
        }
        ans = std::max(ans, sum - l);
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}