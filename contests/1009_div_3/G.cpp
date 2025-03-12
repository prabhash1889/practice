#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 400;
long long dp[MAXN + 2][MAXN + 2];
long long aA[MAXN + 2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> aA[i];
		}
		for (int l = 1; l <= n; l++)
		{
			for (int r = 1; r <= n; r++)
			{
				dp[l][r] = 0;
			}
		}
		for (int length = 3; length <= n; length++)
		{
			for (int l = 1; l + length - 1 <= n; l++)
			{
				int r = l + length - 1;
				long long bestVal = dp[l + 1][r];

				for (int m = l + 1; m <= r; m++)
				{
					for (int x = m + 1; x <= r; x++)
					{
						long long val = (long long)aA[l] * aA[m] * aA[x];
						if (m - 1 >= l + 1)
							val += dp[l + 1][m - 1];
						if (x - 1 >= m + 1)
							val += dp[m + 1][x - 1];
						if (r >= x + 1)
							val += dp[x + 1][r];
						bestVal = max(bestVal, val);
					}
				}

				dp[l][r] = bestVal;
			}
		}

		cout << dp[1][n] << "\n";
	}

	return 0;
}
