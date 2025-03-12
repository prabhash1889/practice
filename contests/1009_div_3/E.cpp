#include <bits/stdc++.h>
using namespace std;

int query(int i, int j, int k)
{
	cout << "? " << i << " " << j << " " << k << endl;
	int res;
	cin >> res;
	if (res == -1)
		exit(0);
	return res;
}

void answer(int i, int j, int k)
{
	cout << "! " << i << " " << j << " " << k << endl;
}

void solve()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> cand = {1, 2, 3};
		while (true)
		{
			int ret = query(cand[0], cand[1], cand[2]);
			if (ret == 0)
				break;
			int p = ret;
			if (query(cand[0], cand[1], p) == 0)
			{
				cand[2] = p;
				break;
			}
			if (query(cand[0], p, cand[2]) == 0)
			{
				cand[1] = p;
				break;
			}
			if (query(p, cand[1], cand[2]) == 0)
			{
				cand[0] = p;
				break;
			}
			cand[0] = cand[1];
			cand[1] = cand[2];
			cand[2] = p;
		}
		answer(cand[0], cand[1], cand[2]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
