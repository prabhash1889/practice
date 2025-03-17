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
		vector<tuple<int, int, int>> ops;

		int pairs = N / 2;
		for (int i = 0; i < pairs; i++)
		{
			int j = N - 1 - i;
			if (A[i] == B[i] && A[j] == B[j])
				continue;
			if (A[i] != B[i] && A[j] != B[j])
			{
				if (A[i] == A[j])
				{
					ops.push_back({1, i + 1, j + 1});
					for (int k = i; k <= j; k++)
					{
						A[k] = (A[k] == '0' ? '1' : '0');
					}
				}
				else
				{
					ops.push_back({2, i + 1, j + 1});
					reverse(A.begin() + i, A.begin() + j + 1);
				}
			}
			else
			{
				if (A[i] != B[i])
				{
					ops.push_back({1, i + 1, i + 1});
					A[i] = (A[i] == '0' ? '1' : '0');
				}
				if (A[j] != B[j])
				{
					ops.push_back({1, j + 1, j + 1});
					A[j] = (A[j] == '0' ? '1' : '0');
				}
			}
		}

		if (N % 2 == 1)
		{
			int mid = N / 2;
			if (A[mid] != B[mid])
			{
				ops.push_back({1, mid + 1, mid + 1});
				A[mid] = (A[mid] == '0' ? '1' : '0');
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
