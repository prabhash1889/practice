#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	auto min_op=[&](string &s){
		int n=s.size();
		int min_ops=1E18;
		for(char c='a';c<='z';c++){
			int m_b=0,c_b=0;
			for(int i=0;i<n;i++){
				if(s[i]!=c){
					c_b++;
				}
				else{
					m_b=max(m_b,c_b);
					c_b=0;
				}
			}
			m_b=max(m_b,c_b);
			int ops=(m_b>0)?(int)ceil(log2(m_b+1)):0;
			min_ops=min(min_ops,ops);
		}
		return min_ops;
	};


	int t;
	cin>>t;
	while(t--){
		string s;cin>>s;
		cout<<min_op(s)<<'\n';

	}
	
	return 0;
}

