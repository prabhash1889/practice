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
		string A, B;
		cin >> A >> B;
		vector<int> a(N), b(N);
		for (int i = 0; i < N; i++)
		{
			a[i] = A[i] - '0';
			b[i] = B[i] - '0';
		}
		vector<tuple<int, int, int>> ops;

		int pairs = N / 2;
		for (int i = 0; i < pairs; i++)
		{
			int j = N - 1 - i;
			if (a[i] == b[i] && a[j] == b[j])
				continue;
			if (a[i] != b[i] && a[j] != b[j])
			{
				if (a[i] == a[j])
				{
					ops.push_back({1, i + 1, j + 1});
					a[i] = 1 - a[i];
					a[j] = 1 - a[j];
				}
				else
				{
					ops.push_back({2, i + 1, j + 1});
					swap(a[i], a[j]);
				}
			}
			else
			{
				if (a[i] != b[i])
				{
					ops.push_back({1, i + 1, i + 1});
					a[i] = 1 - a[i];
				}
				if (a[j] != b[j])
				{
					ops.push_back({1, j + 1, j + 1});
					a[j] = 1 - a[j];
				}
			}
		}
		if (N % 2 == 1)
		{
			int mid = N / 2;
			if (a[mid] != b[mid])
			{
				ops.push_back({1, mid + 1, mid + 1});
				a[mid] = 1 - a[mid];
			}
		}
		cout << ops.size() << "\n";
		for (auto &op : ops)
		{
			int t, L, R;
			tie(t, L, R) = op;
			cout << t << " " << L << " " << R << "\n";
		}
	}
	return 0;
}
