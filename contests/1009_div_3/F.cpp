#include <bits/stdc++.h>
using namespace std;

void decompose1D(long long l, long long r, vector<long long> &freq)
{
	while (l < r)
	{
		long long length = (r - l);
		long long p = 1LL << (63 - __builtin_clzll(length));
		while (p > 0 && (l % p != 0))
		{
			p >>= 1;
		}
		if (p == 0)
			p = 1;

		int k = __builtin_ctzll(p);
		freq[k]++;
		l += p;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	static long long p2[41];
	for (int i = 0; i < 41; i++)
	{
		p2[i] = (1LL << i);
	}

	int t;
	cin >> t;
	while (t--)
	{
		long long l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		vector<long long> freqX(21, 0), freqY(21, 0);
		decompose1D(l1, r1, freqX);
		decompose1D(l2, r2, freqY);

		long long ans = 0;
		for (int a = 0; a <= 20; a++)
		{
			if (!freqX[a])
				continue;
			for (int b = 0; b <= 20; b++)
			{
				if (!freqY[b])
					continue;
				long long mul = freqX[a] * freqY[b];
				int diff = abs(a - b);
				long long val = p2[diff];
				ans += mul * val;
			}
		}

		cout << ans << "\n";
	}
	return 0;
}
