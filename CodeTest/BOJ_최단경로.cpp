#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>

struct tEdge
{
	int node;
	int w;

	bool operator <(const tEdge& _rhs) const
	{
		return w < _rhs.w;
	}
	bool operator >(const tEdge& _rhs) const
	{
		return w > _rhs.w;
	}
};

int main()
{
	fastio;

	int V, E;
	cin >> V >> E;

	int S;
	cin >> S;

	vector<vector<tEdge>> adjList(V+1);
	for (int i = 0; i < E; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		adjList[s].push_back({ d,w });
	}
	const int INF = 1'000'000'000;
	vector<int> table(V+1, INF);
	vector<bool> visited(V+1);

	std::priority_queue<tEdge, vector<tEdge>, std::greater<>> PQ;
	table[S] = 0;
	PQ.push({S, 0});

	while (!PQ.empty())
	{
		auto top = PQ.top();
		PQ.pop();

		if (visited[top.node]) continue;
		visited[top.node] = true;

		for (auto [node, w] : adjList[top.node])
		{
			if (top.w + w < table[node])
			{
				table[node] = top.w + w;
				PQ.push({node, table[node]});
			}
		}
	}

	for (int i = 1; i <= V; ++i)
	{
		if (table[i] == INF)
			cout << "INF" << "\n";
		else
			cout << table[i]<< "\n";
	}

	return 0;
}


// S : 2:33
// U : 2:34 1min
// T : 2:35 1min
// C : 2:58 23min
// Total : 25min