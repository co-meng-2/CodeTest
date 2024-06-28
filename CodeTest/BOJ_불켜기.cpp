#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int n, m;

vector<pii> board[100][100]{};
bool visited[100][100]{};
bool lighted[100][100]{};
set<pii> unlightedSet;

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= n || x >= n;
}

int main()
{
	fastio;

	cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		int y, x, swy, swx;
		cin >> y >> x >> swy >> swx;
		board[y-1][x-1].push_back({ swy-1, swx-1 });
	}

	queue<pii> Q;
	Q.push({0, 0});
	visited[0][0] = true;
	lighted[0][0] = true;

	while(!Q.empty())
	{
		auto [cy, cx] = Q.front();
		Q.pop();

		for(auto [by, bx] : board[cy][cx])
		{
			lighted[by][bx] = true;

			if (visited[by][bx] || unlightedSet.find({ by,bx }) == unlightedSet.end()) continue;

			visited[by][bx] = true;
			Q.push({ by,bx });
		}

		for(int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (OOB(ny, nx) || visited[ny][nx]) continue;

			if (!lighted[ny][nx]) 
				unlightedSet.insert({ ny,nx });
			else
			{
				visited[ny][nx] = true;
				Q.push({ ny, nx });
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (lighted[i][j]) ans++;
	cout << ans;

	return 0;
}


// S : 10 22
// U : 10 22 0min
// T : 10 26 4min
// C : 11 17 51min 
// Total : 55min

// Comment
// 정답이 불을 킬 수 있는 최대 방의 갯수이다. 들어갈 수 있는 최대 방의 갯수가 아니라ㅋㅋㅋ...
// 저 정답 말장난에만 30분 썼다.