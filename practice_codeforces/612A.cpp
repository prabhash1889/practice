// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int n,p,q;
// 	cin>>n>>p>>q;
// 	string s;
// 	cin>>s;
// 	if(2*p>n and 2*q>n){
// 		cout<<-1<<'\n';
// 	}
// 	else{
// 		if(q<p){
// 			swap(p,q);
// 		}
// 		cout<<2<<'\n';
// 		cout<<s.substr(0,p)<<"\n";
// 		cout<<s.substr(p,2*p)<<"\n";

// }
// }
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,p,q;
	cin>>n>>p>>q;
	string s;
	cin>>s;
	for(int i=0;i*p<=n;i++){
		if((n-i*p)%q==0){
			cout<<i+(n-i*p)/q<<'\n';
			int j=0;
			while(j<i*p){
				cout<<s.substr(j,p)<<'\n';
				j+=p;
			}
			while(j<n){
				cout<<s.substr(j,q)<<'\n';
				j+=q;
			}
			return 0;
		}
	}
	cout<<-1<<'\n';
	return 0;
}