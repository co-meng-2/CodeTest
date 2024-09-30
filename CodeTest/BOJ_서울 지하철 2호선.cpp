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

// 위상정렬 방식을 이용해 사이클 판정 가능.

int n;
int degree[3001]{};
bool visited[3001]{};
vector<int> adjList[3001]{};


int main()
{
	fastio;
	cin >> n;
	for(int i = 1 ;i <= n; ++i)
	{
		int a, b;
		cin >> a >> b;
		++degree[a];
		++degree[b];
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	queue<int> Q;
	for(int i = 1; i <= n; ++i)
	{
		if(degree[i] == 1)
		{
			Q.push(i);
		}
	}

	while(!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		--degree[cur];

		for(auto nxt : adjList[cur])
		{
			if(degree[nxt])
			{
				--degree[nxt];
				if (degree[nxt] == 1)
					Q.push(nxt);
			}
		}
	}

	for(int i = 1; i <=n; ++i)
	{
		memset(visited, false, sizeof(visited));
		if (degree[i] > 0)
		{
			cout << 0 << " ";
		}
		else
		{
			queue<int> Q;
			Q.push(i);
			visited[i] = true;
			int dist = 0;
			while(!Q.empty())
			{
				int qsz = Q.size();
				++dist;
				while(qsz--)
				{
					int cur = Q.front();
					Q.pop();

					for(auto nxt : adjList[cur])
					{
						if (visited[nxt]) continue;
						visited[nxt] = true;
						Q.push(nxt);

						if (degree[nxt] > 0)
						{
							cout << dist << " ";
							qsz = 0;
							Q = {};
						}
					}
				}
			}
		}
	}

	return 0;
}


// S : 2 15
// U : 2 20
// T : 2 25
// C : 2 38
// Total : 23min
