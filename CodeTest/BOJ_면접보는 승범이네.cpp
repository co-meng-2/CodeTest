#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;
const ll LINF = numeric_limits<ll>::max() / 2;

// 면접장 까지의 최대 거리 = max(dist[연결된 노드들], dist[자신]);

ll dist[100001]{};

int n, m, k;

int main()
{
	fastio;
	cin >> n >> m >> k;
	fill(dist, dist + n + 1, LINF);

	vector<vector<pii>> adjList(n + 1);
	for(int i = 0; i < m; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		adjList[d].push_back({ w,s });
	}

	priority_queue<pli, vector<pli>, greater<>> PQ;
	for(int i = 0; i < k; ++i)
	{
		int idx;
		cin >> idx;
		dist[idx] = 0;
		PQ.push({ 0, idx });
	}

	while(!PQ.empty())
	{
		auto [cw, cur] = PQ.top();
		PQ.pop();

		if (cw != dist[cur]) continue;

		for(auto [cost, nxt] : adjList[cur])
		{
			if(dist[nxt] > dist[cur] + cost)
			{
				dist[nxt] = dist[cur] + cost;
				PQ.push({ dist[nxt], nxt });
			}
		}
	}

	int FarCity = -1;
	ll FarDist = -1;
	for(int i = 1; i <=n; ++i)
	{
		if(FarDist < dist[i])
		{
			FarCity = i;
			FarDist = dist[i];
		}
	}

	cout << FarCity << "\n" << FarDist;
	return 0;
}


// S : 1 54
// U : 1 55
// T : 1 57
// C : 2 14
// Total : 20min
