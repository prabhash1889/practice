#include<bits/stdc++.h>
using namespace std;
// using ll =long long



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int64_t k, p;
	cin >> k >> p;
	auto sum_zcy = [](int k, int p) {
		int64_t sum = 0;
		for (int i = 1; i <= k; i++) {
			string s = to_string(i);
			string t = s+string(s.rbegin(), s.rend());
			// reverse(t.begin(), t.end());
			// s += t;
			sum += stoll(t);
			sum %= p;
		}
		cout << sum << endl;
	};
	sum_zcy(k, p);
	return 0;

}