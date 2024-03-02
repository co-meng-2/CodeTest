#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>

// bfs memo
// memo[x][y]는 위치까지의 필요한 최소 거울의 갯수

using pii = std::pair<int, int>;
struct tPos
{
	int y;
	int x;
	int dirIdx;
};

pii dirs[4] = { {1,0},{0,1},{-1,0},{0,-1} };

vector<int> GetPossibleDir(int cur)
{
	vector<int> possibles;
	possibles.push_back(cur);
	if (cur + 1 < 4)
		possibles.push_back(cur + 1);
	else
		possibles.push_back(0);

	if (cur - 1 >= 0)
		possibles.push_back(cur - 1);
	else
		possibles.push_back(3);

	return possibles;
}

int main()
{
	fastio;
	int x, y;
	cin >> x >> y;
	vector<vector<char>> board(y + 2, vector<char>(x + 2, '*'));
	vector<tPos> SD;
	for (int i = 1; i <= y; ++i)
		for (int j = 1; j <= x; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 'C')
				SD.push_back({ i, j });
		}

	const int INF = 1'000'000'000;

	vector<vector<vector<pii>>> memo;
	memo.resize(y + 2);
	for(auto& it : memo)
	{
		it.resize(x + 2);
		for(auto& it2 : it)
		{
			it2.resize(4, {INF ,0});
		}
	}
	for (int i = 0; i < 4; ++i)
		memo[SD[0].y][SD[0].x][i] = { 0,0 };

	std::queue<tPos> q;
	for(int i = 0; i < 4; ++i)
	{
		q.push({ SD[0].y, SD[0].x, i});
	}
	
	while(!q.empty())
	{
		auto [cy,cx,cd] = q.front();
		q.pop();
		int cMemo = memo[cy][cx][cd].first;

		vector<int> possibles = GetPossibleDir(cd);
		for(auto dir : possibles)
		{
			int nMemo = cMemo;
			if (dir != cd)
				nMemo += 1;

			int ny = cy + dirs[dir].first;
			int nx = cx + dirs[dir].second;
			
			if (board[ny][nx] == '*') continue;
			if (memo[ny][nx][dir].first < nMemo) continue;
			if (memo[ny][nx][dir].first == nMemo && memo[ny][nx][dir].second == true) continue;
			memo[ny][nx][dir].second = true;
			memo[ny][nx][dir].first = nMemo;
			q.push({ ny, nx, dir});
		}
	}
	int min = INF;

	for (auto it : memo[SD[1].y][SD[1].x])
		min = std::min(min, it.first);
	cout << min;


	return 0;
}


// S : 10:20
// U : 10:21
// T : 10:26
// C :
// Total :