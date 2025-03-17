#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
	long long b_S;
	int b_L;
	vector<vector<int>> cc;
	vector<long long> e_W;
	vector<int> P;
	vector<long long> m_A;

	long long c_AA(int u)
	{
		long long best = 0;
		for (int v : cc[u])
		{
			long long ccc = e_W[v] + c_AA(v);
			best = max(best, ccc);
		}
		m_A[u] = best;
		return best;
	}

	void dfsSubtree(int u, long long ssf, int lsf, bool uT,
					unordered_map<int, int> &freq, const vector<int> &nums)
	{
		if (ssf + m_A[u] < b_S)
		{
			return;
		}

		if (ssf > b_S)
		{
			b_S = ssf;
			b_L = lsf;
		}
		else if (ssf == b_S && lsf < b_L)
		{
			b_L = lsf;
		}

		for (int v : cc[u])
		{
			int val = nums[v];
			int o_CC = freq[val];

			if (o_CC == 0)
			{
				freq[val] = 1;
				dfsSubtree(v, ssf + e_W[v], lsf + 1, uT, freq, nums);
				freq[val] = 0;
			}
			else if (o_CC == 1 && !uT)
			{
				freq[val] = 2;
				dfsSubtree(v, ssf + e_W[v], lsf + 1, true, freq, nums);
				freq[val] = 1;
			}
		}
	}

public:
	vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
	{
		int n = (int)nums.size();
		if (n == 0)
			return {0, 0};

		vector<vector<pair<int, long long>>> graph(n);
		for (auto &e : edges)
		{
			int u = e[0], v = e[1];
			long long w = e[2];
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});
		}

		P.assign(n, -1);
		e_W.assign(n, 0LL);
		P[0] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto &p : graph[u])
			{
				int v = p.first;
				long long w = p.second;
				if (P[v] == -1 && v != 0)
				{
					P[v] = u;
					e_W[v] = w;
					q.push(v);
				}
			}
		}

		cc.assign(n, {});
		for (int i = 1; i < n; i++)
		{
			cc[P[i]].push_back(i);
		}

		m_A.assign(n, 0LL);
		c_AA(0);

		b_S = 0LL;
		b_L = 1; 
		for (int start = 0; start < n; start++)
		{
			unordered_map<int, int> freq;
			freq[nums[start]] = 1;
			dfsSubtree(start, 0LL, 1, false, freq, nums);
		}

		return {(int)b_S, b_L};
	}
};
