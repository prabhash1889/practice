// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	ll t;
// 	cin >> t;

// 	while (t--)
// 	{
// 		ll n, m;
// 		cin >> n >> m;
// 		vector<pair<ll, ll>> seg(m);
// 		for (ll i = 0; i < m; i++)
// 		{
// 			cin >> seg[i].first >> seg[i].second;
// 		}
// 		ll q;
// 		cin >> q;
// 		vector<ll> changes(q);
// 		for (ll i = 0; i < q; i++)
// 		{
// 			cin >> changes[i];
// 		}
// 		ll l = 0, r = q, ans = -1;
// 		while (l < r)
// 		{
// 			ll mid = (l + r) / 2;
// 			vector<ll> a(n + 1, 0);
// 			for (ll i = 0; i <= mid; i++)
// 			{
// 				a[changes[i] - 1] = 1;
// 			}
// 			vector<ll> prefix(n + 1, 0);
// 			for (ll i = 1; i <= n; i++)
// 			{
// 				prefix[i] = prefix[i - 1] + a[i - 1];
// 			}
// 			bool found = false;
// 			for (auto [l, r] : seg)
// 			{
// 				ll ones = prefix[r] - prefix[l - 1];
// 				ll length = r - l + 1;
// 				if (ones * 2 > length)
// 				{
// 					found = true;
// 					break;
// 				}
// 			}
// 			if (found)
// 			{
// 				ans = mid + 1;
// 				r = mid;
// 			}
// 			else
// 			{
// 				l = mid + 1;
// 			}
// 		}
// 		cout << ans << '\n';
// 	}
// }

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int>l(m),r(m);
		for(int i=0;i<m;i++){
			cin>>l[i]>>r[i];
			l[i]--;
		}
		int q;
		cin>>q;
		vector<int>x(q);
		for(int i=0;i<q;i++){
			cin>>x[i];
			x[i]--;
		}
		int lo=0,hi=q+1;
		while(lo<hi){
			int t=(lo+hi)/2;
			vector<int>s(n+1);
			for(int i=0;i<t;i++){
				s[x[i]+1]=1;
			}
			for(int i=1;i<=n;i++){
				s[i]+=s[i-1];
			}
			bool ok=false;
			for(int i=0;i<m;i++){
				if((s[r[i]]-s[l[i]])>(r[i]-l[i])/2){
					ok=true;
				}
			}
			if(ok){
				hi=t;
			}
			else{
				lo=t+1;
			}
		}
		int ans=lo;
		if(ans>q) ans=-1;
		cout<<ans<<'\n';
	}
}