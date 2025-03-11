#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
long long modexp(long long base, long long exp)
{
	long long result = 1 % MOD;
	base %= MOD;
	while (exp > 0)
	{
		if (exp & 1)
			result = (result * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return result;
}

static const int MAXN = 200000;
static vector<long long> fact(MAXN + 1), invFact(MAXN + 1);

void initFactorials(int n)
{
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	invFact[n] = modexp(fact[n], MOD - 2);
	for (int i = n - 1; i >= 0; i--)
	{
		invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
	}
}

long long nCr(int n, int r)
{
	if (r < 0 || r > n)
		return 0;
	return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void ntt(vector<long long> &a, bool invert)
{
	int n = (int)a.size();
	for (int i = 1, j = 0; i < n; i++)
	{
		int bit = n >> 1;
		for (; j & bit; bit >>= 1)
		{
			j ^= bit;
		}
		j ^= bit;
		if (i < j)
			std::swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1)
	{
		long long wlen = modexp(3, (MOD - 1) / len);
		if (invert)
			wlen = modexp(wlen, MOD - 2);
		for (int i = 0; i < n; i += len)
		{
			long long w = 1;
			for (int j = 0; j < len / 2; j++)
			{
				long long u = a[i + j], v = (a[i + j + len / 2] * w) % MOD;
				long long t = u + v;
				a[i + j] = t >= MOD ? t - MOD : t;
				t = u - v;
				a[i + j + len / 2] = t < 0 ? t + MOD : t;
				w = (w * wlen) % MOD;
			}
		}
	}
	if (invert)
	{
		long long invN = modexp(n, MOD - 2);
		for (int i = 0; i < n; i++)
		{
			a[i] = (a[i] * invN) % MOD;
		}
	}
}
vector<long long> multiplyPoly(const vector<long long> &A,
							   const vector<long long> &B)
{
	int sz = 1;
	while (sz < (int)(A.size() + B.size() - 1))
		sz <<= 1;
	vector<long long> FA(sz, 0), FB(sz, 0);
	for (int i = 0; i < (int)A.size(); i++)
		FA[i] = A[i];
	for (int i = 0; i < (int)B.size(); i++)
		FB[i] = B[i];
	ntt(FA, false);
	ntt(FB, false);
	for (int i = 0; i < sz; i++)
	{
		FA[i] = (FA[i] * FB[i]) % MOD;
	}
	ntt(FA, true);
	FA.resize(A.size() + B.size() - 1);
	return FA;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	initFactorials(MAXN);

	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;

		int p = 0;
		for (char c : s)
		{
			if (c == '1')
				p++;
		}

		vector<long long> Warr(2 * n + 1, 0LL);
		auto G = [&](int m)
		{
			if (m < 2)
				return 0LL;
			long long half1 = m / 2;
			long long half2 = (m + 1) / 2;
			return (half1 * half2) % MOD;
		};
		for (int i = 0; i <= 2 * n; i++)
		{
			int dist = abs(i - n);
			Warr[i] = G(dist);
		}

		vector<long long> B(n + 1, 0LL);
		for (int x = 0; x <= n; x++)
		{
			B[x] = nCr(n, x);
		}

		vector<long long> R(2 * n + 1);
		for (int i = 0; i <= 2 * n; i++)
		{
			R[i] = Warr[2 * n - i];
		}

		auto M = multiplyPoly(R, B);

		vector<long long> Sarr(n + 1, 0LL);
		for (int k = 0; k <= n; k++)
		{
			int idx = 2 * n - k;
			if (idx >= 0 && idx < (int)M.size())
			{
				Sarr[k] = (M[idx] % MOD + MOD) % MOD;
			}
			else
			{
				Sarr[k] = 0;
			}
		}
		while (q--)
		{
			int i;
			cin >> i;
			i--;
			if (s[i] == '0')
			{
				s[i] = '1';
				p++;
			}
			else
			{
				s[i] = '0';
				p--;
			}
			cout << Sarr[p] << "\n";
		}
	}
	return 0;
}
