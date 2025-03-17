#include <bits/stdc++.h>
using namespace std;

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

		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			sum += a;
		}

		// The mximum possible final value after n-1 operations.
		cout << sum - (n - 1) << "\n";
	}

	return 0;
}
