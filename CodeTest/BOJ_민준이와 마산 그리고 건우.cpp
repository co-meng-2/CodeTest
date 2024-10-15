#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using pii = pair<int, int>;

int v, e, p;
vector<pii> adjList[5001];
int table[5001]{};

int dijk(int s, int d)
{
	memset(table, INF, sizeof(table));
	table[s] = 0;

	priority_queue<pii, vector<pii>, greater<>> PQ;
	PQ.push({ 0,s });
	while(!PQ.empty())
	{
		auto [cw, cur] = PQ.top();
		PQ.pop();

		if (cw != table[cur]) continue;
		if (cur == d) break;

		for(auto [nw, nxt] : adjList[cur])
		{
			if (cw + nw >= table[nxt]) continue;
			table[nxt] = cw + nw;
			PQ.push({ table[nxt], nxt });
		}
	}
	return table[d];
}

int main()
{
	fastio;
	cin >> v >> e >> p;
	for(int i = 0; i < e; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		adjList[s].push_back({ w,d });
		adjList[d].push_back({ w,s });
	}

	if (dijk(1, v) == dijk(1, p) + dijk(p, v))
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";


	return 0;
}

// S : 335
// U : 336
// T : 338
// C : 345
// Total : 10min
