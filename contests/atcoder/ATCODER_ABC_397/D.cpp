// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	int n;cin>>n;
// 	bool f=false;
// 	int64_t x_A=0,y_A=0;
// 	for(int64_t i=1;i<=1000000;i++){
// 		int64_t C=i*i*i+n;
// 		int64_t l=1,r=1200000;
// 		while(l<=r){
// 			int64_t mid=(l+r)/2;
// 			int64_t C2=mid*mid*mid;
// 			if(C2==C){
// 				x_A=mid;
// 				y_A=i;
// 				f=true;
// 				break;
// 			}else if(C2<C){
// 				l=mid+1;
// 			}else{
// 				r=mid-1;
// 			}
// 		}
// 		if(f)break;
// 	}
// 	if(f){
// 		cout<<x_A<<" "<<y_A<<"\n";
// 	}else{
// 		cout<<-1<<"\n";
// 	}
// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define ull  unsigned long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ull n;
	cin>>n;
	bool f=false;
	ull x_A=0,y_A=0;
	ull d_m;
	{
		ull l=1,r=1600000;
		while(l<=r){
			ull mid=(l+r)/2;
			if(mid*mid*mid<=4*n){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		d_m=r;
	}
	auto isqrt=[&](ull n){
		ull lo=0,hi=(1ULL<<32);
		while(lo<hi){
			ull mid=(lo+hi+1)>>1;
			if(mid*mid<=n)lo=mid;
			else hi=mid-1;
		}
		return lo;
	};
	for(ull d=1;d<=d_m;d++){
		if(n%d!=0)continue;
		ull q=n/d;
		if(12*q<3*d*d)continue;
		ull D=12*q-3*d*d;
		ull r=isqrt(D);
		if(r*r!=D)continue;
		if(r-3*d<=0)continue;
		ull y=(r-3*d)/6;
		if(y==0)continue;
		ull x=y+d;
		x_A=x;
		y_A=y;
		f=true;
		break;
	}
	if(f){
		cout<<x_A<<" "<<y_A<<"\n";
	}else{
		cout<<-1<<"\n";
	}
	return 0;	

}