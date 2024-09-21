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

int v, e;

int main()
{
	fastio;
	
	cin >> v >> e;

	vector<vector<pii>> adjList(v + 1);
	// a < b
	int sum = 0;
	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;

		adjList[a].push_back({-1, b});
		adjList[b].push_back({ 1, a });
	}

	
	int ans = 0;
	for (int i = 1; i <= v; ++i)
	{
		vector<bool> visited(v + 1);
		queue<pii> Q;

		Q.push({ -1, i });
		Q.push({ 1, i });
		visited[i] = true;
		int cnt = 1;

		while (!Q.empty())
		{
			auto [cw, cur] = Q.front();
			Q.pop();

			for (auto [nw, nxt] : adjList[cur])
			{
				if (nw != cw || visited[nxt]) continue;
				visited[nxt] = true;
				++cnt;
				Q.push({ nw, nxt });
			}
		}

		if (cnt == v)
			++ans;
	}

	cout << ans;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
