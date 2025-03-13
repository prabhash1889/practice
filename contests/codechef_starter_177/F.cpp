#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
vector<int> tree[MAXN];
int N, K;
pair<int, int> bfs(int start)
{
	vector<int> dist(N + 1, -1);
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	int farthest = start, maxDist = 0;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int neighbor : tree[node])
		{
			if (dist[neighbor] == -1)
			{
				dist[neighbor] = dist[node] + 1;
				q.push(neighbor);
				if (dist[neighbor] > maxDist)
				{
					maxDist = dist[neighbor];
					farthest = neighbor;
				}
			}
		}
	}
	return {farthest, maxDist};
}
vector<int> findDiameter()
{
	int A = bfs(1).first;
	int B = bfs(A).first;
	vector<int> parent(N + 1, -1);
	queue<int> q;
	q.push(B);
	parent[B] = B;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int neighbor : tree[node])
		{
			if (parent[neighbor] == -1)
			{
				parent[neighbor] = node;
				q.push(neighbor);
			}
		}
	}
	vector<int> path;
	for (int v = A; v != B; v = parent[v])
		path.push_back(v);
	path.push_back(B);
	return path;
}

void solve()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		tree[i].clear();
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	vector<int> labels(N + 1, 0);
	if (K == 0)
	{
		cout << "1\n";
		for (int i = 1; i <= N; i++)
			cout << "0 ";
		cout << "\n";
		return;
	}
	vector<int> diameterPath = findDiameter();
	for (int i = 0; i < K; i++)
		labels[diameterPath[i]] = 1;
	cout << "2\n";
	for (int i = 1; i <= N; i++)
		cout << labels[i] << " ";
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}
