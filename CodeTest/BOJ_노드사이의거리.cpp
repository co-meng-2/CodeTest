#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>

struct edge
{
	int node;
	int w;
};

void dfs(int cur, int d, int w, vector<vector<edge>>& adjList, vector<int>& ans, vector<bool>& visited)
{
	if (visited[cur]) return;
	visited[cur] = true;

	if (cur == d)
	{
		ans.push_back(w);
		return;
	}

	for (auto it : adjList[cur])
	{
		dfs(it.node, d, it.w + w, adjList, ans, visited);
	}
}

int main()
{
	fastio;

	int N, M;
	cin >> N >> M;

	// 인접리스트
	vector<vector<edge>> adjList(N+1);

	for (int i = 0; i < N - 1; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		adjList[s].push_back({ d, w });
		adjList[d].push_back({ s, w });
	}

	vector<int> ans;

	for (int i = 0; i < M; ++i)
	{
		int s, d;
		cin >> s >> d;
		vector<bool> visited(N+1);

		// BFS
		std::queue<edge> q;
		q.push({s,0});
		
		while (!q.empty())
		{
			auto front = q.front();
			q.pop();

			if (visited[front.node]) continue;
			visited[front.node] = true;

			if (front.node == d)
			{
				ans.push_back(front.w);
				break;
			}

			for (auto it : adjList[front.node])
			{
				q.push({ it.node, front.w + it.w });
			}
		}

		// DFS
		dfs(s, d, 0, adjList, ans, visited);
	}

	for (auto it : ans)
	{
		cout << it << "\n";
	}

	return 0;
}


// S : 11:10
// U : 11:12
// T : 11:14
// C : 11:40
// Total : 30min

// visited를 써야하는 이유에 대해
// 정점이 양 방향 그래프로 연결되어야 한다.
// 주어진 경로가 2 - 1 - 3 이렇게 연결되어야 하는 경우에 단 방향 그래프로 오름차순 또는 내림차순으로 트리를 정렬하여
// 단 방향 그래프로 만들어도 2 - 1이나 1 - 3으로 가는 경로가 유실된다.
// 따라서 전에 방문했던 정점을 제외하기 위해 visited가 필요한 문제이다.