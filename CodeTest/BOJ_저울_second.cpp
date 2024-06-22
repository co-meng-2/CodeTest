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
#include <set>
#include <string>
using namespace std;

using ll = long long;
using pii = pair<int, int>;



int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	vector<vector<pii>> adjList(n+1);
	for(int i = 0; i < m; ++i)
	{
		int big, small;
		cin >> big >> small;
		adjList[big].push_back({ small, 1});
		adjList[small].push_back({ big, -1 });
	}

	for(int i = 1; i  < adjList.size(); ++i)
	{
		int ans = n - 1;
		queue<pii> Q;
		Q.push({ i, 1 });
		Q.push({ i,-1 });
		vector<bool> visited(n + 1, false);
		visited[i] = true;
		while(!Q.empty())
		{
			auto [cur, w] = Q.front();
			Q.pop();

			for(auto [nxt, nw] : adjList[cur])
			{
				if (nw != w || visited[nxt]) continue;
				visited[nxt] = true;
				Q.push({ nxt, nw });
				ans--;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}


// S : 909
// U : 
// T : 
// C :
// Total :