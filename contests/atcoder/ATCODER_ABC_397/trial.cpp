#include <bits/stdc++.h>
using namespace std;

// Edge structure
struct Edge
{
	int u, v;
};

int N, M, K;
vector<Edge> edges;		 // list of all edges (indexed 0..M-1)
vector<vector<int>> adj; // adj[u]: list of edge indices leaving u
vector<int> assigned;	 // assigned[i] == 1 means edge i has weight 1; else 0.

// Global: target value (we want shortest distance from 1 to N >= target)
int targetD;

// Global vector to store one shortest path (as a list of edge indices)
vector<int> globalPath;

// A large constant for infinity.
const int INF = 1e9;

// 0-1 BFS: computes the shortest path (in number of ones) from 1 to N
// Also recovers one such path in globalPath.
int bfsShortestPath()
{
	vector<int> dist(N + 1, INF);
	// For each vertex, store the edge index used to reach it
	vector<int> parentEdge(N + 1, -1);
	deque<int> dq;
	dist[1] = 0;
	dq.push_back(1);
	while (!dq.empty())
	{
		int u = dq.front();
		dq.pop_front();
		if (u == N)
			break;
		for (int ei : adj[u])
		{
			int v = edges[ei].v;
			int w = assigned[ei]; // cost is 0 if not chosen, 1 if chosen.
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				parentEdge[v] = ei;
				if (w == 0)
					dq.push_front(v);
				else
					dq.push_back(v);
			}
		}
	}
	// If N unreachable (should not happen by problem statement) return INF.
	if (dist[N] == INF)
		return INF;
	// Recover one shortest path from 1 to N
	globalPath.clear();
	int cur = N;
	while (cur != 1)
	{
		int ei = parentEdge[cur];
		globalPath.push_back(ei);
		cur = edges[ei].u;
	}
	reverse(globalPath.begin(), globalPath.end());
	return dist[N];
}

// ---
// For memoization, we define a key that encodes the current assignment of ones and the remaining budget.
// Because M can be up to 100, we store the assignment in two 64–bit numbers.
struct State
{
	unsigned long long maskLow, maskHigh; // first 64 and next bits (M <= 100)
	int rem;
	bool operator==(const State &other) const
	{
		return maskLow == other.maskLow && maskHigh == other.maskHigh && rem == other.rem;
	}
};

struct StateHash
{
	std::size_t operator()(const State &s) const
	{
		auto h1 = std::hash<unsigned long long>()(s.maskLow);
		auto h2 = std::hash<unsigned long long>()(s.maskHigh);
		auto h3 = std::hash<int>()(s.rem);
		return ((h1 ^ (h2 << 1)) >> 1) ^ (h3 << 1);
	}
};

unordered_map<State, bool, StateHash> memo;

// Helper: record the current assignment as a State.
State getState()
{
	State s;
	s.maskLow = 0;
	s.maskHigh = 0;
	for (int i = 0; i < M; i++)
	{
		if (assigned[i])
		{
			if (i < 64)
				s.maskLow |= (1ULL << i);
			else
				s.maskHigh |= (1ULL << (i - 64));
		}
	}
	s.rem = K; // we will pass rem separately in DFS (the DFS parameter)
	return s;  // Note: we do not include rem here because that is passed as parameter.
}

// DFS that, given rem (remaining ones we can add), tries to force the shortest-path distance >= targetD.
// Returns true if possible.
bool dfs(int rem)
{
	int d = bfsShortestPath();
	// If current cost is already at least targetD, we are done.
	if (d >= targetD)
		return true;
	// Prune: even if we set ones on every edge on the current shortest path,
	// the best we can add is (rem) extra ones.
	if (d + rem < targetD)
		return false;
	// For memo: we record a hash based on the current assignment and remaining budget.
	State st;
	st.maskLow = 0;
	st.maskHigh = 0;
	for (int i = 0; i < M; i++)
	{
		if (assigned[i])
		{
			if (i < 64)
				st.maskLow |= (1ULL << i);
			else
				st.maskHigh |= (1ULL << (i - 64));
		}
	}
	st.rem = rem;
	if (memo.count(st))
		return memo[st];

	// globalPath now holds a shortest s-t path (with cost < targetD)
	// Try “blocking” this path by switching on one edge (that is not already chosen).
	for (int ei : globalPath)
	{
		if (assigned[ei] == 0)
		{
			assigned[ei] = 1;
			if (dfs(rem - 1))
			{
				memo[st] = true;
				assigned[ei] = 0;
				return true;
			}
			assigned[ei] = 0;
		}
	}
	memo[st] = false;
	return false;
}

// ---
// In main we binary–search on target D (from 0 up to at most N–1; note that a simple s-t path
// has at most N–1 edges). For each candidate, we check whether it is possible to force the
// 1-to-N distance (i.e. the minimum number of ones used on a 1-to-N path) to be at least D
// by choosing exactly K edges (or fewer, then “padding” to K arbitrarily).

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	edges.resize(M);
	adj.assign(N + 1, vector<int>());
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		edges[i] = {u, v};
		// Build the adjacency list (directed)
		adj[u].push_back(i);
	}
	assigned.assign(M, 0);

	// Lower bound of answer is 0; upper bound is at most (N-1).
	int lo = 0, hi = N - 1, ans = 0;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		targetD = mid;
		memo.clear();
		// DFS uses at most K ones (we start with rem = K)
		if (dfs(K))
		{
			ans = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	cout << ans << "\n";
	return 0;
}
