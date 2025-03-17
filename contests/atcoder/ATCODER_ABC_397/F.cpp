#include <bits/stdc++.h>
using namespace std;

struct SegTree{
	int n;
	vector<int> tree, lazy;
	SegTree(int n) : n(n){
		tree.assign(4 * n, -1000000000);
		lazy.assign(4 * n, 0);
	}
	void apply(int idx, int l, int r, int val){
		tree[idx] += val;
		lazy[idx] += val;
	}
	void pushDown(int idx, int l, int r){
		if (lazy[idx] != 0){
			int mid = (l + r) / 2;
			apply(idx * 2, l, mid, lazy[idx]);
			apply(idx * 2 + 1, mid + 1, r, lazy[idx]);
			lazy[idx] = 0;
		}
	}
	void updateRange(int idx, int l, int r, int ql, int qr, int val){
		if (ql > r || qr < l)
			return;
		if (ql <= l && r <= qr){
			apply(idx, l, r, val);
			return;
		}
		pushDown(idx, l, r);
		int mid = (l + r) / 2;
		updateRange(idx * 2, l, mid, ql, qr, val);
		updateRange(idx * 2 + 1, mid + 1, r, ql, qr, val);
		tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
	}
	int queryRange(int idx, int l, int r, int ql, int qr){
		if (ql > r || qr < l)
			return -1000000000;
		if (ql <= l && r <= qr)
			return tree[idx];
		pushDown(idx, l, r);
		int mid = (l + r) / 2;
		return max(queryRange(idx * 2, l, mid, ql, qr),
				   queryRange(idx * 2 + 1, mid + 1, r, ql, qr));
	}
	void update(int l, int r, int val) { updateRange(1, 1, n, l, r, val); }
	int query(int l, int r) { return queryRange(1, 1, n, l, r); }
	void updatePoint(int idx, int l, int r, int pos, int val){
		if (l == r){
			tree[idx] = val;
			return;
		}
		pushDown(idx, l, r);
		int mid = (l + r) / 2;
		if (pos <= mid)
			updatePoint(idx * 2, l, mid, pos, val);
		else
			updatePoint(idx * 2 + 1, mid + 1, r, pos, val);
		tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
	}
	void updatePoint(int pos, int val) { updatePoint(1, 1, n, pos, val); }
};
struct Fenw{
	int n;
	vector<int> fenw;
	Fenw(int n) : n(n) { fenw.assign(n + 1, 0); }
	void update(int i, int delta){
		for (; i <= n; i += i & -i)
			fenw[i] += delta;
	}
	int query(int i){
		int s = 0;
		for (; i > 0; i -= i & -i)
			s += fenw[i];
		return s;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; i++){
		cin >> A[i];
	}
	vector<int> L(N + 1, 0), R(N + 2, 0);
	vector<int> l_o(N + 1, 0);
	int dn = 0;
	for (int i = 1; i <= N; i++){
		if (l_o[A[i]] == 0)
		{
			dn++;
			l_o[A[i]] = i;
		}
		L[i] = dn;
	}
	fill(l_o.begin(), l_o.end(), 0);
	dn = 0;
	for (int i = N; i >= 1; i--){
		if (l_o[A[i]] == 0)
		{
			dn++;
			l_o[A[i]] = i;
		}
		R[i] = dn;
	}
	SegTree seg(N);
	Fenw fenw(N);
	vector<int> dp(N + 1, 0);
	vector<int> l_val(N + 1, 0);
	fenw.update(1, 1);
	l_val[A[1]] = 1;
	dp[1] = L[1] - fenw.query(1);
	seg.updatePoint(1, dp[1]);
	int ans = -1000000000;
	for (int j = 2; j <= N - 1; j++){
		int x = A[j];
		if (l_val[x] != 0){
			int p = l_val[x];
			if (p <= j - 1)
				seg.update(p, j - 1, 1);
			fenw.update(p, -1);
		}
		fenw.update(j, 1);
		l_val[x] = j;
		dp[j] = L[j] - fenw.query(j);
		seg.updatePoint(j, dp[j]);
		int best = seg.query(1, j - 1);
		int cnd = L[j] + best + R[j + 1];
		ans = max(ans, cnd);
	}
	cout << ans << "\n";
	return 0;
}