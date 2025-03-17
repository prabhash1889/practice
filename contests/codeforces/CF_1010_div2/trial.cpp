#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<int> longestCommonPrefix(vector<string> &words, int k)
	{
		int n = words.size();
		if (n - 1 < k)
			return vector<int>(n, 0);

		vector<string> dd = words;

		int mx_L = 0;
		for (const auto &w : words)
			mx_L = max(mx_L, (int)w.size());

		vector<unordered_map<string, int>> pf_C(mx_L + 1);
		for (const auto &w : words)
		{
			int len = w.size();
			for (int L = 1; L <= len; L++)
			{
				string pf = w.substr(0, L);
				pf_C[L][pf]++;
			}
		}

		vector<int> fmax(mx_L + 1, 0), fsec(mx_L + 1, 0), c_mx(mx_L + 1, 0);
		vector<string> pmax(mx_L + 1, "");
		for (int L = 1; L <= mx_L; L++)
		{
			for (const auto &pr : pf_C[L])
			{
				int cnt = pr.second;
				if (cnt > fmax[L])
				{
					fsec[L] = fmax[L];
					fmax[L] = cnt;
					pmax[L] = pr.first;
					c_mx[L] = 1;
				}
				else if (cnt == fmax[L])
				{
					c_mx[L]++;
				}
				else if (cnt > fsec[L])
				{
					fsec[L] = cnt;
				}
			}
		}

		typedef unsigned long long ull;
		const ull base = 131ULL;
		vector<ull> pr(mx_L + 1, 1);
		for (int i = 1; i <= mx_L; i++)
		{
			pr[i] = pr[i - 1] * base;
		}

		vector<vector<ull>> w_H(n);
		for (int i = 0; i < n; i++)
		{
			int len = words[i].size();
			w_H[i].resize(len + 1, 0);
			for (int j = 0; j < len; j++)
			{
				w_H[i][j + 1] = w_H[i][j] * base + (words[i][j] - 'a' + 1);
			}
		}

		vector<ull> p_H(mx_L + 1, 0);
		for (int L = 1; L <= mx_L; L++)
		{
			if (!pmax[L].empty())
			{
				ull h = 0;
				for (char c : pmax[L])
				{
					h = h * base + (c - 'a' + 1);
				}
				p_H[L] = h;
			}
		}

		vector<int> ans(n, 0);
		for (int i = 0; i < n; i++)
		{
			int lo = 1, hi = mx_L, best = 0;
			while (lo <= hi)
			{
				int mid = (lo + hi) / 2;
				bool valid = false;
				if (mid > (int)words[i].size())
				{
					valid = (fmax[mid] >= k);
				}
				else
				{
					if (w_H[i][mid] == p_H[mid] && c_mx[mid] == 1)
					{
						valid = (max(fmax[mid] - 1, fsec[mid]) >= k);
					}
					else
					{
						valid = (fmax[mid] >= k);
					}
				}
				if (valid)
				{
					best = mid;
					lo = mid + 1;
				}
				else
				{
					hi = mid - 1;
				}
			}
			ans[i] = best;
		}
		return ans;
	}
};
