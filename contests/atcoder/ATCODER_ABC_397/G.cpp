#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int u, v;
};
int N, M, K;
vector<Edge> edges;
vector<vector<int>> adj;
vector<int> asgn;
int targetD;
vector<int> g_P;
const int INF = 1e9;
int bfsShortestPath(){
	vector<int> dist(N + 1, INF);
	vector<int> p_Edge(N + 1, -1);
	deque<int> dq;
	dist[1] = 0;
	dq.push_back(1);
	while (!dq.empty()){
		int u = dq.front();
		dq.pop_front();
		if (u == N)
			break;
		for (int ei : adj[u]){
			int v = edges[ei].v;
			int w = asgn[ei];
			if (dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				p_Edge[v] = ei;
				if (w == 0)
					dq.push_front(v);
				else
					dq.push_back(v);
			}
		}
	}
	if (dist[N] == INF)
		return INF;
	g_P.clear();
	int cur = N;
	while (cur != 1){
		int ei = p_Edge[cur];
		g_P.push_back(ei);
		cur = edges[ei].u;
	}
	reverse(g_P.begin(), g_P.end());
	return dist[N];
}
struct State{
	unsigned long long m_L, m_H;
	int rem;
	bool operator==(const State &oth) const{
		return m_L == oth.m_L && m_H == oth.m_H && rem == oth.rem;
	}
};
struct StateHash{
	size_t operator()(const State &s) const{
		auto h1 = std::hash<unsigned long long>()(s.m_L);
		auto h2 = std::hash<unsigned long long>()(s.m_H);
		auto h3 = std::hash<int>()(s.rem);
		return ((h1 ^ (h2 << 1)) >> 1) ^ (h3 << 1);
	}
};
unordered_map<State, bool, StateHash> memo;
State getState(int rem){
	State s;
	s.m_L = 0;
	s.m_H = 0;
	for (int i = 0; i < M; i++){
		if (asgn[i]){
			if (i < 64)
				s.m_L |= (1ULL << i);
			else
				s.m_H |= (1ULL << (i - 64));
		}
	}
	s.rem = rem;
	return s;
}
bool dfs(int rem){
	if (rem < 0)
		return false;
	int d = bfsShortestPath();
	if (d >= targetD)
		return true;
	if (d + rem < targetD)
		return false;
	State st = getState(rem);
	if (memo.count(st))
		return memo[st];
	for (int ei : g_P){
		if (asgn[ei] == 0){
			asgn[ei] = 1;
			if (dfs(rem - 1)){
				memo[st] = true;
				asgn[ei] = 0;
				return true;
			}
			asgn[ei] = 0;
		}
	}
	memo[st] = false;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	edges.resize(M);
	adj.assign(N + 1, vector<int>());
	for (int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;
		edges[i] = {u, v};
		adj[u].push_back(i);
	}
	asgn.assign(M, 0);
	int lo = 0, hi = N - 1, ans = 0;
	while (lo <= hi){
		int mid = (lo + hi) / 2;
		targetD = mid;
		memo.clear();
		if (dfs(K)){
			ans = mid;
			lo = mid + 1;
		}
		else{
			hi = mid - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
