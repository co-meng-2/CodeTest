#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

struct tEdge
{
	int d;
	int w;
};

// dfs bfs -> 50000 * 50000 시간초과
// n이 400인걸 이용해서 dfs로 해결
// memo[x][y] x가 y보다 선행하면 -1, x가 y보다 후행하면 1, 모르면 0
// memoization!!!!!!

void dfs(int start, int cur, int opt, vector<vector<int>>& dp, vector<vector<tEdge>>& adjList, vector<bool>& visited)
{
	// 선행
	for (auto [d, w] : adjList[cur])
	{
		if (w != opt) continue;
		if (visited[d]) continue;
		visited[d] = true;
		dp[start][d] = opt;
		dfs(start, d, opt, dp, adjList, visited);
	}
}

int main()
{
	fastio;

	int v, e;
	cin >> v >> e;

	vector<vector<int>> floyd(v+1, vector<int>(v+1, 0));
	for (int i = 0; i < e; ++i)
	{
		int s, d;
		cin >> s >> d;
		floyd[s][d] = -1;
		floyd[d][s] = 1;
	}

	for (int k = 1; k <= v; ++k)
	{
		for (int i = 1; i <= v; ++i)
		{
			for (int j = 1; j <= v; ++j)
			{
				if (floyd[i][j] == 0 && floyd[i][k] == floyd[k][j])
					floyd[i][j] = floyd[i][k];
			}
		}
	}

	int T;
	cin >> T;
	while (T--)
	{
		int s, d;
		cin >> s >> d;
		cout << floyd[s][d] << "\n";
	}


	// dfs
	vector<vector<int>> dp(v + 1, vector<int>(v + 1, 0));
	vector<vector<tEdge>> adjList(v + 1);
	for (int i = 0; i < e; ++i)
	{
		int s, d;
		cin >> s >> d;
		adjList[s].push_back({ d, -1 });
		adjList[d].push_back({ s, 1 });
	}

	vector<bool> visited(v + 1, false);
	for (int i = 1; i <= v; ++i)
	{
		dfs(i, i, -1, dp, adjList, visited);
		std::fill(visited.begin(), visited.end(), false);
		dfs(i, i, 1, dp, adjList, visited);
		std::fill(visited.begin(), visited.end(), false);
	}

	int T;
	cin >> T;
	while (T--)
	{
		int s, d;
		cin >> s >> d;
		cout << dp[s][d] << "\n";
	}

	return 0;
}


// S : 608
// U : 608
// T : 613
// C : 635
// Total : 27min

