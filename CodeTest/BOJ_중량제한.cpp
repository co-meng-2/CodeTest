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

// A와 B를 잇는 경로 중 가장 작은 값이 큰 값인 경로의 가장 작은 값을 구하라.

int n, m;

int main()
{
	fastio;

	cin >> n >> m;

	vector<vector<pii>> adjList(n + 1);
	for(int i = 0; i < m; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		adjList[s].push_back({ w, d });
		adjList[d].push_back({ w, s });
	}

	int s, d;
	cin >> s >> d;

	vector<int> table(n + 1, 0);
	priority_queue<pii> PQ;
	table[s] = INF;
	PQ.push({INF, s});

	while(!PQ.empty())
	{
		auto [cw, cur] = PQ.top();
		PQ.pop();

		if (table[cur] != cw) continue;

		for(auto [nw, nxt] : adjList[cur])
		{
			int val = min(cw, nw);
			if (table[nxt] >= val) continue;
			table[nxt] = val;
			PQ.push({ val, nxt });
		}
	}

	cout << table[d];

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
