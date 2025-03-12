#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<ll> centers(n), radii(n);
		for (int i = 0; i < n; i++)
		{
			cin >> centers[i];
		}
		int max_r = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> radii[i];
			max_r = max(max_r, (int)radii[i]);
		}
		int height = 2 * max_r + 1;
		vector<vector<pair<ll, ll>>> rows(height);

		for (int i = 0; i < n; i++)
		{
			int r_i = radii[i];
			ll x_i = centers[i];
			for (int y = -r_i; y <= r_i; y++)
			{
				ll inside = (ll)r_i * r_i - (ll)y * y;
				int d = (int)floor(sqrt((long double)inside));
				ll L = x_i - d;
				ll R = x_i + d;
				int idx = y + max_r;
				rows[idx].push_back({L, R});
			}
		}

		ll ans = 0;
		for (int i = 0; i < height; i++)
		{
			if (rows[i].empty())
				continue;
			sort(rows[i].begin(), rows[i].end());
			ll curL = rows[i][0].first, curR = rows[i][0].second;
			ll rowCount = 0;
			for (size_t j = 1; j < rows[i].size(); j++)
			{
				ll L = rows[i][j].first, R = rows[i][j].second;
				if (L <= curR + 1)
				{
					curR = max(curR, R);
				}
				else
				{
					rowCount += (curR - curL + 1);
					curL = L;
					curR = R;
				}
			}
			rowCount += (curR - curL + 1);
			ans += rowCount;
		}

		cout << ans << "\n";
	}
	return 0;
}
