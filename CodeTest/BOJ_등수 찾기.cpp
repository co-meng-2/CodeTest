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

// 1 -> 2-> 3 -> 4 -> 5 
// 이런식으로 화살표(잘한 순서)가 이어져있을때, 총 학생의 수가 n명이라고 하면 4의 범위는  2 ~ (n-5) + 2

int n, m, x;

int main()
{
	fastio;

	cin >> n >> m >> x;

	vector<vector<pii>> adjList(n+1);
	for (int i = 0; i < m; ++i)
	{
		int s, d;
		cin >> s >> d;
		adjList[s].push_back({ 1,d }); 
		adjList[d].push_back({ -1,s });
	}

	queue<int> Q;
	Q.push(x);

	int bcnt = 0;
	vector<bool> visited(n + 1, false);
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (auto [w, nxt] : adjList[cur])
		{
			if (w == 1 && !visited[nxt])
			{
				Q.push(nxt);
				bcnt++;
				visited[nxt] = true;
			}
		}
	}

	Q.push(x);
	int fcnt = 0;
	fill(visited.begin(), visited.end(), false);
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (auto [w, nxt] : adjList[cur])
		{
			if (w == -1 && !visited[nxt])
			{
				Q.push(nxt);
				fcnt++;
				visited[nxt] = true;
			}
		}
	}

	cout << fcnt + 1 << " " << n - bcnt;
	
	return 0;
}


// S : 9 46
// U : 9 48
// T : 9 56
// C : 10 10
// Total : 24min

// Comment
