#include <bits/stdc++.h>
using namespace std;

const int B = -1;
const int F = -2;
int N, K;
vector<vector<int>> adj;

int dfs(int v, int p){
	int c = 0;
	vector<int> P;
	for (auto u : adj[v]){
		if (u == p)
			continue;
		int r = dfs(u, v);
		if (r == F)
			return F;
		if (r != B)
		{
			int val = r + 1;
			if (val == K - 1)
				c++;
			else
				P.push_back(val);
		}
	}
	if (c > 1)
		return F;
	if (c == 1){
		if (!P.empty())
			return F;
		return B;
	}
	int sz = P.size();
	if (sz == 0)
		return 0;
	else if (sz == 1)
		return P[0];
	else if (sz == 2)
	{
		if (P[0] + P[1] == K - 1)
			return B;
		else
			return F;
	}
	else
		return F;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	int t_v = N * K;
	if (K == 1){
		for (int i = 1; i < t_v; i++)
		{
			int u, v;
			cin >> u >> v;
		}
		cout << "Yes\n";
		return 0;
	}
	adj.resize(t_v + 1);
	for (int i = 1; i < t_v; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int res = dfs(1, -1);
	if (res == B)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
