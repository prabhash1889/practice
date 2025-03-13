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
		int N, M;
		cin >> N >> M;
		vector<int> A(N + 1);
		for (int i = 1; i <= N; i++)
		{
			cin >> A[i];
		}
		vector<int> B(M + 1);
		for (int i = 1; i <= M; i++)
		{
			cin >> B[i];
		}
		vector<int> alt(N + 2, 0);
		alt[N] = N;
		alt[N + 1] = N + 1;
		for (int i = N - 1; i >= 1; i--)
		{
			if (A[i] != A[i + 1])
				alt[i] = alt[i + 1];
			else
				alt[i] = i;
		}
		int mx_v = M;
		const int INF = N + 1;
		vector<vector<int>> nxt(N + 2, vector<int>(mx_v + 1, INF));
		for (int v = 1; v <= mx_v; v++)
		{
			nxt[N + 1][v] = INF;
		}
		for (int i = N; i >= 1; i--)
		{
			for (int v = 1; v <= mx_v; v++)
			{
				nxt[i][v] = nxt[i + 1][v];
			}
			int val = A[i];
			nxt[i][val] = i;
		}
		int64_t ans = 0;
		for (int L = 1; L <= N; L++)
		{
			if (A[L] != B[1])
				continue;
			int pos = L;
			bool valid = true;
			for (int k = 2; k <= M; k++)
			{
				if (pos == N)
				{
					valid = false;
					break;
				}
				int l_b = pos + 1;
				if (l_b <= N && A[l_b] == B[k - 1])
				{
					if (A[l_b] == B[k])
					{
						pos = l_b;
					}
					else
					{
						valid = false;
						break;
					}
					continue;
				}
				int a_mx = alt[l_b];
				int cd = nxt[l_b][B[k]];
				while (cd <= N && cd > l_b && cd > a_mx)
				{
					cd = nxt[cd + 1][B[k]];
				}
				if (cd > a_mx)
				{
					valid = false;
					break;
				}
				pos = cd;
			}
			if (!valid)
				continue;
			int r_min = pos;
			int r_max;
			if (pos == N)
				r_max = N;
			else
			{
				int t_s = pos + 1;
				if (t_s <= N && A[t_s] == B[M])
					r_max = pos;
				else
				{
					r_max = alt[t_s];
					if (r_max > N)
						r_max = N;
				}
			}
			if (r_min <= r_max)
				ans += (int64_t)(r_max - r_min + 1);
		}

		cout << ans << "\n";
	}
	return 0;
}
