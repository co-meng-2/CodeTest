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

// 위상정렬

int degree[32001]{};
int n, m;

int main()
{
	fastio;

	cin >> n >> m;
	vector<vector<int>> adjList(n + 1);
	for(int i = 0; i < m; ++i)
	{
		int a, b; // a < b
		cin >> a >> b;
		degree[b]++;
		adjList[a].push_back(b);
	}

	queue<int> Q;
	for(int i = 1; i <=n; ++i)
	{
		if (degree[i] == 0)
			Q.push(i);
	}

	while(!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		cout << cur << " ";

		for(auto nxt : adjList[cur])
		{
			degree[nxt]--;
			if (degree[nxt] == 0)
				Q.push(nxt);
		}
	}


	return 0;
}


// S : 2:32
// U : 2:34
// T : 2:35
// C : 2:42
// Total : 10min
