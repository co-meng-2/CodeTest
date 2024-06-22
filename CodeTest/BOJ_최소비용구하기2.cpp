#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int n, m;
int adjmat[1001][1001]{};
vector<pii> adjList[1001]{};
int table[1001]{};
int s, d;
int path[1001]{};

int main()
{
	fastio;

	cin >> n >> m;
	memset(adjmat, 0x3f, sizeof(adjmat));
	for(int i = 0; i < m; ++i)
	{
		int es, ee, ew;
		cin >> es >> ee >> ew;
		if (adjmat[es][ee] <= ew) continue;
		adjmat[es][ee] = ew;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (adjmat[i][j] != INF)
				adjList[i].push_back({adjmat[i][j], j});

	cin >> s >> d;
	
	priority_queue<tiii, vector<tiii>, greater<>> PQ;
	memset(table, 0x3f, sizeof(table));
	table[s] = 0;
	path[s] = -1;
	PQ.push({ table[s], s, -1 });
	while(!PQ.empty())
	{
		auto [cw, cur, p] = PQ.top();
		PQ.pop();

		if (path[cur] == 0)
			path[cur] = p;

		for(auto [nw, nxt] : adjList[cur])
		{
			if (table[nxt] <= cw + nw) continue;
			table[nxt] = nw + cw;
			PQ.push({table[nxt], nxt, cur});
		}
	}

	cout << table[d] << "\n";

	vector<int> ans;
	while(d != -1)
	{
		ans.push_back(d);
		d = path[d];
	}

	cout << ans.size() << "\n";
	for (auto it = ans.rbegin(); it != ans.rend(); ++it)
		cout << *it << " ";

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :