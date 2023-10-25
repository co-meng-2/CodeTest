#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct tEdge
{
	int s;
	int e;
	long long w;

	bool operator>(const tEdge& _rhs) const
	{
		return w > _rhs.w;
	}
};

bool daj(vector<vector<tEdge>>& edges, long long limit, long long totalMoney, int s, int e)
{
	vector<bool> visited(edges.size(), false);

	const long long INF = 1LL << 62;
	vector<long long> dist(edges.size(), INF);

	priority_queue<tEdge, vector<tEdge>, greater<tEdge>> PQ;
	PQ.push({-1, s, 0});

	while(!PQ.empty())
	{
		auto top = PQ.top();
		PQ.pop();

		if (visited[top.e]) continue;
		visited[top.e] = true;

		for(auto edge : edges[top.e])
		{
			if (edge.w > limit) continue;
			long long sumW = top.w + edge.w;
			if (sumW > totalMoney) continue;

			if(dist[edge.e] > top.w + edge.w)
			{
				dist[edge.e] = top.w + edge.w;
				PQ.push({ top.e, edge.e, dist[edge.e]});
			}
		}
	}

	return dist[e] != INF;
}

int main()
{
	int N, M, A, B;
	long long C;
	cin >> N >> M >> A >> B >> C;
	vector<vector<tEdge>> edges(N+1);

	for(int i = 0;i < M; ++i)
	{
		int s, e;
		long long w;
		cin >> s >> e >> w;
		edges[s].push_back({ s,e,w });
		edges[e].push_back({ e,s,w });
	}

	long long lo = 0; // 반드시 F
	long long hi = 1e9 + 1; // T 또는 F
	while(lo + 1 < hi)
	{
		long long mid = (lo + hi) / 2;

		if(daj(edges, mid, C, A ,B ))
			hi = mid;
		else
			lo = mid;
	}

	// 전부 F
	if (hi == 1e9 + 1)
		cout << -1;
	else
		cout << hi;

	return 0;
}