#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	vector<int> p(n,0);
	vector<bool> S(n+1,false);
	int d=0;
	for(int i=0;i<n;i++){
		if(!S[a[i]]){
			d++;
			S[a[i]]=true;
		}
		p[i]=d;
	}
	vector<int> s(n,0);
	fill(S.begin(),S.end(),false);
	d=0;
	for(int i=n-1;i>=0;i--){
		if(!S[a[i]]){
			d++;
			S[a[i]]=true;
		}
		s[i]=d;
	}
	int ans=0;
	for(int i=0;i<n-1;i++){
		ans=max(ans,p[i]+s[i+1]);
	}
	cout<<ans<<"\n";
	return 0;
}