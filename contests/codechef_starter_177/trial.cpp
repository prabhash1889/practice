#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (k == 0 || k == n)
	{
		cout << 1 << '\n';
		for (int i = 1; i <= n; ++i)
		{
			cout << (k ? 1 : 0) << " \n"[i == n];
		}
		return;
	}
	vector<int> parent(n + 1, -1);
	vector<int> sz(n + 1, 0);

	function<void(int, int)> dfs = [&](int node, int p)
	{
		parent[node] = p;
		sz[node] = 1;
		for (int v : adj[node])
		{
			if (v != p)
			{
				dfs(v, node);
				sz[node] += sz[v];
			}
		}
	};
	dfs(1, -1);

	bool found = false;
	int split_node = -1, split_parent = -1;
	for (int node = 2; node <= n; ++node)
	{
		int p = parent[node];
		int s = sz[node];
		if (s == k || (n - s) == k)
		{
			found = true;
			split_node = node;
			split_parent = p;
			break;
		}
	}
	if (found)
	{
		vector<bool> is_one(n + 1, false);
		bool is_subtree = (sz[split_node] == k);
		if (is_subtree)
		{
			function<void(int, int)> mark = [&](int u, int pu)
			{
				is_one[u] = true;
				for (int v : adj[u])
				{
					if (v != pu)
					{
						mark(v, u);
					}
				}
			};
			mark(split_node, split_parent);
		}
		else
		{
			fill(is_one.begin(), is_one.end(), true);
			function<void(int, int)> unmark = [&](int u, int pu)
			{
				is_one[u] = false;
				for (int v : adj[u])
				{
					if (v != pu)
					{
						unmark(v, u);
					}
				}
			};
			unmark(split_node, split_parent);
		}
		cout << 2 << '\n';
		for (int i = 1; i <= n; ++i)
		{
			cout << (is_one[i] ? 1 : 0) << " \n"[i == n];
		}
	}
	else
	{
		vector<bool> is_one(n + 1, false);
		vector<bool> visited(n + 1, false);
		queue<int> q;
		q.push(1);
		visited[1] = true;
		int cnt = 0;
		while (!q.empty() && cnt < k)
		{
			int u = q.front();
			q.pop();
			is_one[u] = true;
			cnt++;
			for (int v : adj[u])
			{
				if (!visited[v])
				{
					visited[v] = true;
					q.push(v);
				}
			}
		}
		cout << 3 << '\n';
		for (int i = 1; i <= n; ++i)
		{
			cout << (is_one[i] ? 1 : 0) << " \n"[i == n];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}