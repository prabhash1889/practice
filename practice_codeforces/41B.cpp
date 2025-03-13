// #include<bits/stdc++.h>
// using namespace std;


// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int n,b;
// 	cin>>n>>b;
// 	vector<int>p(n);
// 	for(int i=0;i<n;i++){
// 		cin>>p[i];
// 	}

// 	auto mx_bourles=[&](int x,int y,vector<int>& P){
// 		int min_p=P[0];
// 		int max_m=y;
// 		for(int i=1;i<x;i++){
// 			max_m=max(max_m,(y/min_p)*P[i]+(y%min_p));
// 			min_p=min(min_p,P[i]);
// 		}
// 		return max_m;
// 	};

// 	cout<<mx_bourles(n,b,p)<<'\n';
// }
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,b;cin>>n>>b;
	vector<int>p(n);
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	int ans=b;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans=max(ans,b+(p[j]-p[i])*(b/p[i]));
		}
	}
	cout<<ans<<'\n';
}