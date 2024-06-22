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

const int INF = 0x3f3f3f3f;

int n, m, x;

vector<int> dijk(vector<vector<pii>>& adjList)
{
	vector<int> table(n + 1, 1e9);
	priority_queue<pii, vector<pii>, greater<>> PQ;
	PQ.push({ 0,x });
	table[x] = 0;
	while (!PQ.empty())
	{
		auto [cw, s] = PQ.top();
		PQ.pop();

		for (auto [nw, d] : adjList[s])
		{
			if (table[d] <= table[s] + nw) continue;
			table[d] = table[s] + nw;
			PQ.push({ table[d], d });
		}
	}

	return table;
}

int main()
{
	fastio;


	cin >> n >> m >> x;
	vector<vector<pii>> adjList1(n+1);
	vector<vector<pii>> adjList2(n+1);

	for(int i = 0; i <m; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		adjList1[s].push_back({w,d});
		adjList2[d].push_back({ w,s });
	}
	
	vector<int> table1 = dijk(adjList1);
	vector<int> table2 = dijk(adjList2);

	int mx = -1;
	for(int i = 1; i <= n; ++i)
	{
		if (i == x) continue;
		mx = max(table1[i] + table2[i], mx);
	}
	cout << mx;


	return 0;
}


// S : 408
// U : 
// T : 
// C :
// Total :