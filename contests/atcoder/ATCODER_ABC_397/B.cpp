#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int ans = 0;
	char e = 'i';
	int i = 0;
	while (i < s.size())
	{
		if (s[i] == e)
		{
			i++;
			e = (e == 'i' ? 'o' : 'i');
		}
		else
		{
			ans++;
			e = (e == 'i' ? 'o' : 'i');
		}
	}
	if ((s.size() + ans) % 2 == 1)
	{
		ans++;
	}
	cout << ans << "\n";
	return 0;
}
