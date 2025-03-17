#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	double n;
	cin >> n;
	if (n >= 38.0)
	{
		cout << 1 << '\n';
	}
	else if (n >= 37.5 && n < 38)
		cout << 2 << '\n';
	else
		cout << 3 << '\n';
}