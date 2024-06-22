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
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

int dy[3] = { -1, 0, 1 };

int r, c;
bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= r || x >= c;
}

// 위 중간 아래 순으로 우선 순위 dfs

bool visited[10000][500]{};
bool check = false;
int ans = 0;
void dfs(int cy, int cx)
{
	if(cx == c - 1)
	{
		ans++;
		check = true;
		return;
	}

	for(int i = 0; i < 3; ++i)
	{
		int ny = cy + dy[i];
		int nx = cx + 1;
		if (OOB(ny, nx) || visited[ny][nx] == true) continue;
		visited[ny][nx] = true;
		dfs(ny, nx);
		if (check)
			return;
	}
}

int main()
{
	fastio;

	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			char in;
			cin >> in;
			if (in == 'x')
				visited[i][j] = true;
		}

	for(int i = 0; i < r; ++i)
	{
		check = false;
		dfs(i, 0);
	}

	cout << ans;


	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :