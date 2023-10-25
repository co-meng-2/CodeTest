#include <iostream>

#include <queue>

#include <algorithm>

#include <vector>
using namespace std;

struct tEdge
{
	int d;
	int w;

	bool operator>(const tEdge& _rhs) const
	{
		return w < _rhs.w;
	}
};


vector<int> daj(int start, vector<vector<tEdge>> adjList)
{
	const int INF = 1000000000;
	int vCnt = adjList.size();
	vector<int> table(vCnt, INF);
	vector<bool> visited(vCnt, false);

	priority_queue<tEdge, vector<tEdge>, greater<tEdge>> PQ;
	PQ.push({start, 0});

	while(!PQ.empty())
	{
		auto top = PQ.top();
		PQ.pop();

		if (visited[top.d]) continue;
		visited[top.d] = true;

		for(auto adj : adjList[top.d])
		{
			if (table[adj.d] > top.w + adj.w)
			{
				table[adj.d] = top.w + adj.w;
				PQ.push({ adj.d, table[adj.d] });
			}
		}
	}

	return table;
}

const int vCnt = 1000;
vector<int> p(vCnt, -1);
int Find(int n)
{
	if (p[n] < 0) return n;
	return p[n] = Find(p[n]);
}

bool Union(int parent, int child)
{
	parent = p[parent];
	child = p[child];

	if (parent == child) return false;

	p[parent] += p[child];
	p[child] = parent;
}

struct tEXEdge
{
	int s;
	int d;
	int w;

	bool operator<(const tEXEdge& _rhs) const
	{
		return w < _rhs.w;
	}
};

int Cruscal(vector<tEXEdge> edges)
{
	int ans = 0;
	sort(edges.begin(), edges.end());

	for(auto edge : edges)
	{
		if(Union(edge.s ,edge.d))
		{
			ans += edge.w;
		}
	}

	return ans;
}

int Prim(int s, vector<vector<tEdge>> adjList)
{
	int ans = 0;

	vector<bool> visited(adjList.size() + 1, false);

	priority_queue<tEdge, vector<tEdge>, greater<tEdge>> PQ;
	for (auto edge : adjList[s])
	{
		PQ.push(edge);
	}
	visited[s] = true;

	int sumW = 0;
	while(!PQ.empty())
	{
		auto top = PQ.top();
		PQ.pop();

		if (visited[top.d]) continue;
		visited[top.d] = true;
		sumW += top.w;

		for(auto edge : adjList[top.d])
		{
			PQ.push(edge);
		}
	}
	return sumW;
}

int main()
{
	int V, E, K;
	cin >> V >> E >> K;

	vector<vector<tEdge>> adjList(V+1);

	// 그래프를 인접행렬로 만들기
	for (int i = 0; i < E; ++i)
	{
		int from, to, w;
		cin >> from >> to >> w;
		adjList[from].push_back({to, w });
	}

	int ans = Prim(K, adjList);
	// vector<int> ans = daj(K, adjList);

	return 0;
}
