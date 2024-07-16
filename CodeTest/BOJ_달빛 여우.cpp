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

int n, m;

int main()
{
	fastio;

	cin >> n >> m;
	vector<vector<pii>> adjList(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		w *= 2;
		adjList[s].push_back({ w,d });
		adjList[d].push_back({ w,s });
	}

	vector<int> table_fox(n + 1, INF);
	vector<int> visited(n + 1, false);
	table_fox[1] = 0;

	priority_queue<pii, vector<pii>, greater<>> PQ;
	PQ.push({0, 1 });
	while(!PQ.empty())
	{
		auto [cw, cur] = PQ.top();
		PQ.pop();

		if (visited[cur]) continue;
		visited[cur] = true;

		for(auto [nw, nxt] : adjList[cur])
		{
			if (cw + nw >= table_fox[nxt]) continue;
			table_fox[nxt] = cw + nw;
			PQ.push({ table_fox[nxt], nxt });
		}
	}

	vector<vector<int>> table_wolf(2, vector<int>(n + 1, INF)); // 0 -> 2배속으로 도착 | 1 -> 1/2속으로 도착
	vector<vector<bool>> visited_wolf(2, vector<bool>(n + 1, false));
	table_wolf[1][1] = 0;
	// table_wolf[0][1] = 0; -> 이걸 해주면 안된다.... 늑대는 1에 출발하는 시점 전에 1/2속으로 1에 도착한다고 생각해야한다.
	priority_queue<tiii, vector<tiii>, greater<>> PQ_Wolf;
	PQ_Wolf.push({ 0, 1, 0 });
	while(!PQ_Wolf.empty())
	{
		auto [cw, cur, toggle] = PQ_Wolf.top();
		PQ_Wolf.pop();

		if (visited_wolf[!toggle][cur]) continue;
		visited_wolf[!toggle][cur] = true;

		for(auto [nw, nxt] : adjList[cur])
		{
			int cmp = cw + (toggle ? nw * 2 : nw / 2);
			if (cmp >= table_wolf[toggle][nxt]) continue;
			table_wolf[toggle][nxt] = cmp;
			PQ_Wolf.push({cmp, nxt, !toggle});
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if (table_fox[i] < min(table_wolf[0][i], table_wolf[1][i])) ans++;

	cout << ans;

	return 0;
}

// S : 6 21
// U : 6 23
// T : 6 26
// C : 7 37
// Total : 1h 16m

// Comment
// table의 시작을 할당하는 부분에서 자동적으로 입력하던 것이 독이 되었다...
// 시작 조건 때문에 뒤가 망가질 수도 있다는 것을 알게된 문제.
