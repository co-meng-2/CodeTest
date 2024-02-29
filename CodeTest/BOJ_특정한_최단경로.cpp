#include <iostream>
#include <queue>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

using ll = long long;

struct tEdge
{
	int d;
	ll w;

	bool operator>(const tEdge& _rhs) const
	{
		return w > _rhs.w;
	}
};

const ll INF = 1'000'000'000'000'000;

ll dijkstra(int s, int dest, const vector<vector<tEdge>>& adjList, const int& v )
{
	std::priority_queue<tEdge, vector<tEdge>, std::greater<tEdge>> PQ;
	vector<ll> table(v+1, INF);
	vector<bool> visited(v + 1, false);
	PQ.push({ s, 0 });
	table[s] = 0;
	while(!PQ.empty())
	{
		auto [cur, cw] = PQ.top();
		PQ.pop();

		if (visited[cur]) continue;
		visited[cur] = true;

		for(auto [d, nw] : adjList[cur])
		{
			if (table[cur] + nw < table[d])
			{
				table[d] = table[cur] + nw;
				PQ.push({ d, table[d] });
			}
		}
	}

	return table[dest];
}

int main()
{
	fastio;

	int v, e;
	cin >> v >> e;
	vector<vector<tEdge>> adjList(v + 1);
	for(int i = 1; i <=e; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		adjList[s].push_back({ d,w });
		adjList[d].push_back({ s,w });
	}

	int v1, v2;
	cin >> v1 >> v2;
	vector<int> permu;
	permu.push_back(v1);
	permu.push_back(v2);


	std::sort(permu.begin(), permu.end());
	ll min = INF;
	do
	{
		ll d1 = dijkstra(1, permu[0], adjList, v);
		ll d2 = dijkstra(permu[0], permu[1], adjList, v);
		ll d3 = dijkstra(permu[1], v, adjList, v);

		if(d1 != INF && d2 != INF && d3 != INF)
		{
			min = std::min(min, d1 + d2 + d3);
		}

	} while (std::next_permutation(permu.begin(), permu.end()));


	//ll d1 = dijkstra(1, permu[0], adjList, v);
	//ll d2 = dijkstra(permu[0], permu[1], adjList, v);
	//ll d3 = dijkstra(permu[1], v, adjList, v);
	//if (d1 != INF && d2 != INF && d3 != INF)
	//{
	//	min = std::min(min, d1 + d2 + d3);
	//}

	//d1 = dijkstra(1, permu[1], adjList, v);
	//d2 = dijkstra(permu[1], permu[0], adjList, v);
	//d3 = dijkstra(permu[0], v, adjList, v);
	//if (d1 != INF && d2 != INF && d3 != INF)
	//{
	//	min = std::min(min, d1 + d2 + d3);
	//}


	if (min == INF)
		cout << -1;
	else
		cout << min;

	return 0;
}


// S : 10:10
// U : 10:10
// T : 10:16
// C : 
// Total :