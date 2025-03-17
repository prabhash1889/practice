// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);

// 	int N, M;
// 	cin >> N >> M;
// 	int K;
// 	cin >> K;
// 	vector<vector<int>> b_t(N + 1, vector<int>(M + 1, -1));
// 	queue<pair<int, int>> q;
// 	for (int i = 0; i < K; i++)
// 	{
// 		int x, y;
// 		cin >> x >> y;
// 		b_t[x][y] = 0;
// 		q.push({x, y});
// 	}
// 	int dx[4] = {1, -1, 0, 0};
// 	int dy[4] = {0, 0, 1, -1};
// 	while (!q.empty())
// 	{
// 		auto [cx, cy] = q.front();
// 		q.pop();
// 		for (int i = 0; i < 4; i++)
// 		{
// 			int nx = cx + dx[i];
// 			int ny = cy + dy[i];
// 			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && b_t[nx][ny] == -1)
// 			{
// 				b_t[nx][ny] = b_t[cx][cy] + 1;
// 				q.push({nx, ny});
// 			}
// 		}
// 	}
// 	int maxT = -1;
// 	pair<int, int> ans = {1, 1};
// 	for (int i = 1; i <= N; i++)
// 	{
// 		for (int j = 1; j <= M; j++)
// 		{
// 			if (b_t[i][j] > maxT)
// 			{
// 				maxT = b_t[i][j];
// 				ans = {i, j};
// 			}
// 		}
// 	}
// 	cout << ans.first << " " << ans.second << "\n";
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
#else
#define fin std::cin
#define fout std::cout
#endif
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	fin >> N >> M;
	int K;
	fin >> K;
	int size = (N + 1) * (M + 1);
	vector<int> b_t(size, -1);

	auto idx = [&](int x, int y) -> int{
		return x * (M + 1) + y;
	};
	queue<pair<int, int>> q;
	for (int i = 0; i < K; i++){
		int x, y;
		fin >> x >> y;
		b_t[idx(x, y)] = 0;
		q.push({x, y});
	}
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	while (!q.empty()){
		auto [cx, cy] = q.front();
		q.pop();
		int curT = b_t[idx(cx, cy)];
		for (int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M){
				int nid = idx(nx, ny);
				if (b_t[nid] == -1){
					b_t[nid] = curT + 1;
					q.push({nx, ny});
				}
			}
		}
	}
	int maxTime = -1;
	pair<int, int> ans = {1, 1};
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			int cur = b_t[idx(i, j)];
			if (cur > maxTime){
				maxTime = cur;
				ans = {i, j};
			}
		}
	}
	fout << ans.first << " " << ans.second << "\n";
	return 0;
}
