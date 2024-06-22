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
#include <set>
#include <string>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

// bfs
struct tInfo
{
	int w;
	int y;
	int x;

	bool operator>(const tInfo& rhs) const
	{
		return w > rhs.w;
	}
};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int board[1000][1000]{};
int visited[1000][1000]{};
int main()
{
	fastio;
	memset(visited, 0x3f, sizeof(visited));
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		int j = 0;
		for (auto c : str)
		{
			board[i][j] = c - '0';
			j++;
		}
	}

	auto OOB = [&](int y, int x)->bool
	{
		return y < 0 || x < 0 ||  y >= n || x >= m ;
	};
	priority_queue<tInfo, vector<tInfo>, greater<>> PQ;
	PQ.push({0,0,0});
	visited[0][0] = 0;

	while(!PQ.empty())
	{
		auto [cw, cy, cx] = PQ.top();
		PQ.pop();

		for(int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nw = cw;
			if (OOB(ny, nx)) continue;
			if (board[ny][nx] == 1) nw++;

			if (visited[ny][nx] <= nw) continue;
			visited[ny][nx] = nw;
			PQ.push({ nw,ny,nx });
		}
	}

	cout << visited[n - 1][m - 1];

	return 0;
}


// S : 608
// U : 
// T : 
// C :
// Total :