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

const int INF = 0x3f3f3f3f;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char board[50][50]{};
bool visited[26]{};
int r, c;

int ans = 1;

bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= r || x >= c;
}
void dfs(int y, int  x, int cnt)
{
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (OOB(ny, nx)) continue;
		if (visited[board[ny][nx] - 'A'])
		{
			ans = max(ans, cnt);
			continue;
		}
		visited[board[ny][nx] - 'A'] = true;
		dfs(ny, nx, cnt + 1);
		visited[board[ny][nx] - 'A'] = false;
	}
}

int main()
{
	fastio;

	cin >> r >> c;
	
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> board[i][j];

	visited[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << ans;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :