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
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tlii = tuple<ll, int, int>;
using tiiii = tuple<int, int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// 기름 가격이 가장 작은 주유소에서 기름을 채우고 가면 된다.
// 

int v, e;

int main()
{
	fastio;
	
	cin >> v >> e;
	vector<int> oils(v + 1);
	vector<vector<pii>> adjList(v + 1);

	for (int i = 1; i <= v; ++i)
		cin >> oils[i];

	for(int i = 0; i < e; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		adjList[s].push_back({ w,d });
		adjList[d].push_back({ w,s });
	}

	priority_queue<tlii, vector<tlii>, greater<>> PQ; // 비용, 현재위치, 경로의 최소 기름 비용
	PQ.push({ 0,1,2501});
	vector<vector<ll>> table(v + 1, vector<ll>(2502, 1e18));
	table[1][2501] = 0;

	while(!PQ.empty())
	{
		auto [cw, cur, c_oil] = PQ.top();
		PQ.pop();

		if (table[cur][c_oil] < cw) continue;
		if (cur == v) break;

		int n_oil = min(c_oil, oils[cur]);
		for(auto [dist, nxt] : adjList[cur])
		{
			if ( table[nxt][n_oil] <= cw + n_oil * dist) continue;
			table[nxt][n_oil] = cw + n_oil * dist;
			PQ.push({table[nxt][n_oil], nxt, n_oil });
		}
	}

	cout << *min_element(table[v].begin(), table[v].end());

	return 0;
}


// S : 9 18
// U : 9 19
// T : 
// C :
// Total :
