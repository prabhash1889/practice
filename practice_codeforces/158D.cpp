// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int t;
// 	cin >> t;

// 	while (t--)
// 	{
// 		int n;
// 		cin >> n;
// 		vector<int> a(n);
// 		for (int i = 0; i < n; i++)
// 		{
// 			cin >> a[i];
// 		}

// 		auto get_divisors = [&](int x)
// 		{
// 			vector<int> divisors;
// 			for (int i = 1; i * i <= x; i++)
// 			{
// 				if (x % i == 0)
// 				{
// 					divisors.push_back(i);
// 					if (i != x / i)
// 					{
// 						divisors.push_back(x / i);
// 					}
// 				}
// 			}
// 			return divisors;
// 		};

// 		auto max_sc_sum = [&](int x, vector<int> &tt)
// 		{
// 			vector<int> divisors = get_divisors(x);
// 			int max_sum = INT_MIN;
// 			for (int d : divisors)
// 			{
// 				if (d < 3)
// 					continue;

// 				for (int start = 0; start < d; start++)
// 				{
// 					int current_sum = 0;
// 					for (int i = start; i < x; i += d)
// 					{
// 						current_sum += tt[i];
// 					}
// 					max_sum = max(max_sum, current_sum);
// 				}
// 			}
// 			return max_sum;
// 		};

// 		cout << max_sc_sum(n, a) << endl;
// 	}
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int64_t ans = -1E18;
	for (int x = 3; x <= n; x++)
	{
		if (n % x)
		{
			continue;
		}
		for (int i = 0; i < n / x; i++)
		{
			int64_t s = 0;
			for (int j = i; j < n; j += n / x)
			{
				s += a[j];
			}
			ans = max(ans, s);
		}
	}
	cout << ans << '\n';
}