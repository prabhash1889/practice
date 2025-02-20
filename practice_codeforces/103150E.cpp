#include <bits/stdc++.h>
using namespace std;

void solve(int tc = 1)
{
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < n; i++)
	{
		if (t[i] == 'o')
		{
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		solve(t);
	}
}
