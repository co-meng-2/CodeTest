#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;
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

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;


// 최소 거리로 사이클을 판단하면 되지 않을까?

int T;
int N, M, W;

const int MAX = 501;

int floyd[MAX][MAX]{};


int dist1[MAX]{};
void bellman_ford()
{
	cin >> T;
	while (T--)
	{
		memset(floyd, 0x3f, sizeof(floyd));
		memset(dist1, 0x3f, sizeof(dist1));

		cin >> N >> M >> W;

		int s, e, t;

		for (int i = 0; i < M; ++i)
		{
			cin >> s >> e >> t;
			if (floyd[s][e] <= t) continue;
			floyd[s][e] = t;
			floyd[e][s] = t;
		}

		for (int i = 0; i < W; ++i)
		{
			cin >> s >> e >> t;
			if (floyd[s][e] <= -t) continue;
			floyd[s][e] = -t;
		}

		vector<vector<pii>> adjList(N+1);
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (floyd[i][j] != INF)
					adjList[i].push_back({floyd[i][j],j});

		dist1[1] = 0;
		bool negCycle = false;
		for(int iter_cnt = 1; iter_cnt <= N + 1; ++iter_cnt)
		{
			for(int st = 1; st <= N; ++st)
			{
				for(auto [nw, near] : adjList[st])
				{
					if (dist1[near] <= dist1[st] + nw) continue;
					dist1[near] = dist1[st] + nw;
					if (iter_cnt == N + 1)
						negCycle = true;
				}
			}
		}

		if (negCycle)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

void Floyd()
{
	cin >> T;
	while (T--)
	{
		memset(floyd, 0x3f, sizeof(floyd));

		cin >> N >> M >> W;

		int s, e, t;

		for (int i = 0; i < M; ++i)
		{
			cin >> s >> e >> t;
			if (floyd[s][e] <= t) continue;
			floyd[s][e] = t;
			floyd[e][s] = t;
		}

		for (int i = 0; i < W; ++i)
		{
			cin >> s >> e >> t;
			if (floyd[s][e] <= -t) continue;
			floyd[s][e] = -t;
		}


		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				for (int k = 1; k <= N; ++k)
				{
					if (floyd[i][k] != INF && floyd[k][j] != INF)
						floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
				}

		bool flag = false;
		for (int i = 1; i <= N; ++i)
			if (floyd[i][i] < 0)
			{
				cout << "YES" << "\n";
				flag = true;
				break;
			}

		if (!flag)
			cout << "NO" << "\n";
	}
}

int main()
{
	fastio;

	bellman_ford();

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
