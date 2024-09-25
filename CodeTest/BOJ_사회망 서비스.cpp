#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int n;
vector<vector<int>> adjList;
int p[1000001]{};
bool early[1000001]{};
int ans = 0;
void dfs(int cur = 1)
{
	for(auto nxt : adjList[cur])
	{
		if (p[nxt] >= 0) continue;
		p[nxt] = cur;
		dfs(nxt);
	}

	if (!early[cur] && !early[p[cur]])
	{
		early[p[cur]] = true;
		++ans;
	}
}


int main()
{
	fastio;

	memset(p, -1, sizeof(p));
	cin >> n;
	adjList.resize(n + 1);
	for(int i = 0; i < n-1; ++i)
	{
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	early[0] = true;
	p[1] = 0;
	dfs();
	cout << ans;

	return 0;
}


// S : 2 12 
// U : 2 14
// T : 2 25 ~
// C : 2 53
// Total : 41min