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

// 각 정점에서의 최단 경로보다 이동한 곳의 최단 경로가 가까우면 합리적이다.
// 다익스트라로 2번부터 떨어져있는 최단 경로를 모두 구함
// PQ로 현재 거리가 큰 애들부터 순회하면서 어떤 정점까지의 경로가 몇개인지 구한다.
// 이것을 이용해서 다음 정점까지의 경로가 몇개인지 갱신한다.

int main()
{
	fastio;

	int v, e;
	cin >> v >> e;
	vector<vector<pii>> adjList(v);
	for(int i = 0; i < e; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		adjList[s - 1].push_back({ w, d - 1 });
		adjList[d - 1].push_back({ w, s - 1 });
	}

	vector<int> table(v, INF);
	priority_queue<pii, vector<pii>, greater<>> PQ;
	PQ.push({ 0, 1 });
	table[1] = 0;

	while(!PQ.empty())
	{
		auto [cw, cur] = PQ.top();
		PQ.pop();

		for(auto [nw, nxt] : adjList[cur])
		{
			if (table[nxt] <= cw + nw) continue;
			table[nxt] = cw + nw;
			PQ.push({ table[nxt], nxt });
		}
	}
	if(table[0] == INF)
	{
		cout << 0;
		return 0;
	}


	// 정점이 움직일 수 있는 경우는 table[cur] > table[nxt]인 경우이다.
	// 따라서 table 값이 큰 정점부터 이어진 정점까지 위 조건을 검사하며 현재 경로 갯수를 다음 경로 갯수에 더해준다. (그리디)
	// 주의할 점은 이미 PQ안에 들어가 있는 정점을 다시 넣지 않게 pathCnt를 이용해야 한다는 것이다.
	// 굳이 PQ를 안 쓰더라도 sort를 이용해서 할 수 있을지도?
	priority_queue<pii> PQ2;
	vector<int> pathCnt(v, 0);
	pathCnt[0] = 1;
	PQ2.push({ table[0], 0 });
	while(!PQ2.empty())
	{
		auto [minDist, cur] = PQ2.top();
		PQ2.pop();

		for(auto [nw, nxt] : adjList[cur])
		{
			if (table[cur] <= table[nxt]) continue;

			// PQ에 포함되어 있는지를 검사 == visited
			if (pathCnt[nxt] == 0) 
				PQ2.push({ table[nxt], nxt });


			pathCnt[nxt] += pathCnt[cur];
		}
	}

	cout << pathCnt[1];

	return 0;
}


// S : 12 40
// U : 2
// T : 20
// C : 30
// Total : 52min
