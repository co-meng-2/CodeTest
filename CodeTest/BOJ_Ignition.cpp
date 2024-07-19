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
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	vector<vector<pii>> adjList(n + 1);
	for(int i = 0; i < m; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		adjList[s].push_back({ w,d });
		adjList[d].push_back({ w,s });
	}

	float mnTime = 1000000.f;
	for (int i = 1; i <= n; ++i)
	{
		vector<int> table(n + 1, INF);
		table[i] = 0;
		priority_queue<pii> PQ;
		PQ.push({ 0, i });
		
		while(!PQ.empty())
		{
			auto [cw, cur] = PQ.top();
			PQ.pop();

			if (table[cur] != cw) continue;
			
			for(auto [nw, nxt] : adjList[cur])
			{
				if(nw + cw < table[nxt])
				{
					table[nxt] = nw + cw;
					PQ.push({ table[nxt], nxt });
				}
			}
		}

		float mxTime = 0;
		for(int i = 1; i <=n; ++i)
		{
			for(auto [w, d] : adjList[i])
			{
				mxTime = max(mxTime, max(table[i], table[d]) +  (w - abs(table[i] - table[d])) / 2.f);
			}
		}

		mnTime = min(mnTime, mxTime);
	}

	cout << fixed;
	cout.precision(1);
	cout << mnTime;

	return 0;
}

// S : 210
// U : 211
// T : 215
// C : 247
// Total : 
