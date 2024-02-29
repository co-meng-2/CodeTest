#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

using pii = std::pair<int, int>;

void dfs(int cur, int curw, int& far, int& farw, vector<vector<pii>>& adjList, vector<bool>& visited)
{
	if (visited[cur]) return;
	visited[cur] = true;

	if (farw < curw)
	{
		far = cur;
		farw = curw;
	}

	for (auto [nxt, w] : adjList[cur])
	{
		dfs(nxt, w + curw, far, farw, adjList, visited);
	}
}

int main()
{
	fastio;

	int n;
	cin >> n;
	vector<vector<pii>> adjList(n + 1);
	vector<bool> visited(n + 1);

	int i = 1;
	while (i <= n)
	{
		int s;
		cin >> s;
		while (true)
		{
			int d, w;
			cin >> d;
			if (d == -1) break;
			cin >> w;
			// if (s > d) continue;
			adjList[s].push_back({ d,w });
		}
		i++;
	}

	int far = -1;
	int farw = 0;
	dfs(1, 0, far, farw, adjList, visited);
	farw = 0;
	std::fill(visited.begin(), visited.end(), false);
	dfs(far, 0, far, farw, adjList, visited);
	cout << farw;
	
	return 0;
}


// S : 6:05
// U : 
// T : 
// C :
// Total :