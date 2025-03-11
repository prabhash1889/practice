#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int f[10];
	for (int i = 0; i < 10; i++)
	{
		f[i] = (i + 2) * (i + 1) / 2;
	}

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		int64_t res = 1;
		if (n == 0)
			res = f[0];
		else
		{
			while (n > 0)
			{
				int digit = n % 10;
				res *= f[digit];
				n /= 10;
			}
		}
		cout << res << '\n';
	}
}