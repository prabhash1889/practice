// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int t;
// 	cin>>t;

// 	while(t--){
// 		int n,m;
// 		cin>>n>>m;
// 		string s;
// 		cin>>s;
// 		unordered_set<string>st;
// 		for(int i=0;i<m;i++){
// 			int li,ri;
// 			cin>>li>>ri;
// 			li--;
// 			string t=s;
// 			sort(t.begin()+li,t.begin()+ri);
// 			st.insert(t);
// 		}
// 		cout<<st.size()<<'\n';
// 	}
// }	
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		set<pair<int,int>>st;
		vector<int>nxt(n+1,n),lst(n+1,-1);
		for(int i=n-1;i>=0;i--){
			nxt[i]=s[i]=='1'?i:nxt[i+1];
		}
		for(int i=0;i<n;i++){
			lst[i+1]=s[i]=='0'?i:lst[i];
		}
		while(m--){
			int l,r;
			cin>>l>>r;
			l--;
			l=nxt[l];r=lst[r];
			if(l>r){
				l=r=-1;
			}
			st.emplace(l,r);
		}
		cout<<st.size()<<'\n';
	}
}