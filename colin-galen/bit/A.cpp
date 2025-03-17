#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxN=2e5;
ll n,p[mxN];

void solve(int tc=0){
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=a[0];
	for(int i=1;i<n;i++) ans&=a[i];
	cout<<ans<<'\n';
}

int main(){

	int tc=1;
	cin>>tc;
	for(int t=0;t<tc;t++) solve(t);
}