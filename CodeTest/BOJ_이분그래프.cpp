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

	int k;
	cin >> k;
	while(k--)
	{
		int v, e;
		cin >> v >> e;

		vector<int> p(v + 1, -1);
		vector<vector<int>> adjList(v + 1);
		for(int i = 0; i < e; ++i)
		{
			int a, b;
			cin >> a >> b;
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}

		bool valid = true;
		vector<bool> visited(v + 1, false);
		set<int> a;
		set<int> b;
		for(int i = 1; i <= v; ++i)
		{
			if (visited[i]) continue;
			queue<int> Q;
			Q.push(i);

			visited[i] = true;
			a.insert(i);

			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();

				bool nxtBelongsB = false;
				if (a.count(cur))
					nxtBelongsB = true;
				else
					nxtBelongsB = false;

				for (auto nxt : adjList[cur])
				{
					if (nxtBelongsB)
					{
						if (a.count(nxt))
						{
							valid = false;
						}
						else
						{
							if (visited[nxt]) continue;
							visited[nxt] = true;
							Q.push(nxt);
							b.insert(nxt);
						}
					}
					else
					{
						if (b.count(nxt))
						{
							valid = false;
						}
						else
						{
							if (visited[nxt]) continue;
							visited[nxt] = true;
							Q.push(nxt);
							a.insert(nxt);
						}
					}
				}
			}
		}


		cout << (valid ? "YES" : "NO") << "\n";
	}

	return 0;
}


// S : 6 20
// U : 6 21
// T : 6 30
// C : 6 44
// Total :
