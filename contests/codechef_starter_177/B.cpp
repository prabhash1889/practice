#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int X, Y, K;
	cin >> X >> Y >> K;
	int diff = abs(X - Y);
	if (diff == K)
	{
		cout << 0 << "\n";
		return;
	}
	if ((X + Y) < K || (K % 2 != diff % 2))
	{
		cout << -1 << "\n";
		return;
	}
	cout << abs(K - diff) / 2 << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}

	return 0;
}