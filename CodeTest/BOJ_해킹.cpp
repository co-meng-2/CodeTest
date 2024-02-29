#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <queue>

// a�� b�� �����Ѵ� -> b�� �����Ǹ� n�� �� a�� ����
// dfs bfs�� �ð����⵵�� O(v+e) => O(100100) * T = õ������ ���
// �ܹ��� ��������Ʈ ����� �������� ��ǻ�ͺ��� ��ü Ž�� �����ϸ� �� ��
// �ٵ� ���̾Ƹ�� ������� ��ġ�� ���� ��ǻ�Ͱ� ��ġ�� ��찡 �߻�
// �� �� �� ª�� �Ÿ� ���ؾ� ��
// visited �迭�� int�� �����ؼ� �ű������ �ּҰŸ��� ���.
// = ���ͽ�Ʈ�󿴳�?����

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