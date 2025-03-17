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
		int x;
		cin >> x;
		int m = 31 - __builtin_clz(x);
		int candidate = (1 << m) - 1;
		if (candidate == 0)
		{
			cout << -1 << "\n";
			continue;
		}
		int common = x & candidate;
		if (common == 0 || common == candidate)
			cout << -1 << "\n";
		else
			cout << candidate << "\n";
	}
	return 0;
}
