#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <queue>

// a가 b를 의존한다 -> b가 감염되면 n초 뒤 a도 감염
// dfs bfs의 시간복잡도는 O(v+e) => O(100100) * T = 천만정도 충분
// 단방향 인접리스트 만들고 감염당한 컴퓨터부터 전체 탐색 수행하면 될 듯
// 근데 다이아몬드 모양으로 겹치는 감염 컴퓨터가 겹치는 경우가 발생
// 그 중 더 짧은 거만 택해야 함
// visited 배열을 int로 변형해서 거기까지의 최소거리로 사용.
// = 다익스트라였네?ㅋㅋ

using pii = std::pair<int, int>;

int main()
{
	fastio;

	int T;
	cin >> T;

	while(T--)
	{
		int v, e, c;
		cin >> v >> e >> c;

		vector<vector<pii>> adjList(v + 1);
		const int INF = 1'000'000'000;
		for (int i = 0; i < e; ++i)
		{
			int d, s, w;
			cin >> d >> s >> w;
			adjList[s].push_back({ w, d });
		}

		vector<bool> visited(v + 1);
		vector<int> Table(v + 1, INF);
		Table[c] = 0;
		std::priority_queue<pii, vector<pii>, std::greater<pii>> PQ;
		PQ.push({ 0, c });

		while(!PQ.empty())
		{
			auto [w, cur] = PQ.top();
			PQ.pop();
			if (visited[cur]) continue;
			visited[cur] = true;

			for (auto [nxtw, nxt] : adjList[cur])
			{
				if (w + nxtw < Table[nxt])
				{
					Table[nxt] = w + nxtw;
					PQ.push({ Table[nxt], nxt });
				}
			}
		}

		int max = 0;
		int cnt = 0;
		for(auto it : Table)
		{
			if (it != INF)
			{
				cnt++;
				max = std::max(max, it);
			}
		}
		cout << cnt << " " << max << "\n";
	}

	while (T--)
	{
		int v, e, c;
		cin >> v >> e >> c;

		vector<vector<pii>> adjList(v+1);
		const int INF = 1'000'000'000;
		vector<int> visited(v + 1, INF);
		for(int i = 0; i < e; ++i)
		{
			int d, s, w;
			cin >> d >> s >> w;
			adjList[s].push_back({ d, w });
		}

		std::queue<pii> q;
		visited[c] = 0;
		q.push({ c, visited[c]});
		while(!q.empty())
		{
			auto [cur, acc] = q.front();
			q.pop();

			for(auto [nxt, w] : adjList[cur])
			{
				int nxtacc = acc + w;
				if(visited[nxt] > nxtacc)
				{
					visited[nxt] = nxtacc;
					q.push({ nxt, nxtacc });
				}
			}
		}

		int cnt = 0;
		int max = 0;
		for(int i = 1; i < visited.size(); ++i)
		{
			if (visited[i] != INF)
			{
				cnt++;
				max = std::max(max, visited[i]);
			}
		}

		cout << cnt << " " << max << "\n";
	}

	return 0;
}


// S : 12:47
// U : 12:48
// T : 12:53
// C : 1:16
// Total : 29min