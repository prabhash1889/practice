// #include<bits/stdc++.h>
// using namespace std;


// const int BITS=8;

// struct TrieNode{
// 	TrieNode* next[2];
// 	TrieNode(){
// 		next[0]=next[1]=nullptr;
// 	}
// };

// class Trie{
// 	public:
// 		TrieNode* root;
// 		Trie(){
// 			root=new TrieNode();
// 		}

// 		void insert(int num){
// 			TrieNode* node=root;
// 			for(int i=BITS-1;i>=0;--i){
// 				int bit=(num>>i)&1;
// 				if(!node->next[bit]){
// 					node->next[bit]=new TrieNode();
// 				}
// 				node=node->next[bit];
// 			}
// 		}

// 		int maxXOR(int num){
// 			TrieNode* node=root;
// 			int max_xor=0;
// 			for(int i=BITS-1;i>=0;i--){
// 				int bit=(num>>i)&1;
// 				int opposite=1-bit;
// 				if(node->next[opposite]){
// 					max_xor|=(1<<i);
// 					node=node->next[opposite];
// 				}
// 				else{
// 					node=node->next[bit];
// 				}
// 			}
// 			return max_xor;
// 		}
// };




// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int t;
// 	cin>>t;

// 	while(t--){
// 		int n;
// 		cin>>n;
// 		vector<int>a(n);
// 		for(int i=0;i<n;i++){
// 			cin>>a[i];
// 		}		
// 		Trie trie;
// 		int prefixXor=0,max_strength=0;
// 		trie.insert(0);

// 		for(int i=0;i<n;i++){
// 			prefixXor^=a[i];
// 			trie.insert(prefixXor);
// 			max_strength=max(max_strength,trie.maxXOR(prefixXor));
// 		}
// 		cout<<max_strength<<endl;
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
		int n;cin>>n;
		vector<int>a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		vector<int>s(n+1);
		int ans=0;
		for(int i=0;i<n;i++){
			s[i+1]=s[i]^a[i];
		}
		sort(s.begin(),s.end());
		s.erase(unique(s.begin(),s.end()),s.end());
		for(int i=0;i<s.size();i++){
			for(int j=0;j<i;j++){
				ans=max(ans,s[i]^s[j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}