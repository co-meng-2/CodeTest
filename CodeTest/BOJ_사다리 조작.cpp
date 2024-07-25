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
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int n, m, h;
bool adjMat[32][12]{};

bool check()
{
	for(int i = 1; i < n; ++i)
	{
		pii cur = { 1, i };
		while(cur.first <= h)
		{
			auto [r, c] = cur;
			if (adjMat[r][c])
				cur.second++;
			else if (adjMat[r][c-1])
				cur.second--;

			cur.first++;
		}
		if (cur.second != i)
			return false;
	}
	return true;
}

int mn = INF;
void dfs(pii cur, int cnt, bool bCheck)
{
	if (bCheck && check())
	{
		mn = min(cnt, mn);
		return;
	}
	if (cnt >= 3) return;

	auto [r, c] = cur;

	if (r > h) return;
	int nc = c + 1;
	int nr = r;
	if(nc == n)
	{
		nc = 1;
		nr++;
		// if (nr > h) return; - BAD
	}

	if (adjMat[r][c] || adjMat[r][c-1] || adjMat[r][c+1])
	{
		dfs({ nr, nc }, cnt, false);
	}
	else
	{
		adjMat[r][c] = true;
		dfs({ nr,nc }, cnt + 1, true);	
		adjMat[r][c] = false;

		dfs({ nr, nc }, cnt, false);
	}
	
}

int main()
{
	fastio;

	cin >> n >> m >> h;
	for(int i = 0; i < m ; ++i)
	{
		int r, c;
		cin >> r >> c;
		adjMat[r][c] = true;
	}

	dfs({1,1}, 0, true);

	cout << ((mn == INF) ? -1 : mn);
	

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
