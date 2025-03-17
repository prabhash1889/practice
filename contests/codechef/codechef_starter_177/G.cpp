#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
		}
		int64_t tp = (int64_t)N * (N - 1) / 2;
		unordered_map<int, int64_t> cnt;
		cnt.reserve(N * 15);
		for (int x : A)
		{
			vector<int> bits;
			for (int bit = 0; bit < 30; bit++)
			{
				if (x & (1 << bit))
					bits.push_back(bit);
			}
			int sz = bits.size();
			for (int mask = 1; mask < (1 << sz); mask++)
			{
				int sk = 0;
				for (int j = 0; j < sz; j++)
				{
					if (mask & (1 << j))
						sk |= (1 << bits[j]);
				}
				cnt[sk]++;
			}
		}
		int64_t op = 0;
		for (auto &p : cnt)
		{
			int64_t c = p.second;
			if (c >= 2)
			{
				int bis = __builtin_popcount(p.first);
				int64_t pairs = c * (c - 1LL) / 2;
				if (bis % 2 == 1)
					op += pairs;
				else
					op -= pairs;
			}
		}
		int64_t ans = tp + op;
		cout << ans << "\n";
	}
	return 0;
}
