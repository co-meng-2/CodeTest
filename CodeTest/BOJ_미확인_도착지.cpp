#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <queue>


struct tEdge
{
	int d, w;
	bool b;

	bool operator>(const tEdge& rhs) const
	{
		return w > rhs.w;
	}
};

int main()
{
	fastio;

	int T;
	cin >> T;
	while (T--)
	{
		int n, m, t;
		cin >> n >> m >> t;
		int s, g, h;
		cin >> s >> g >> h;

		vector<vector<tEdge>> adjList(n+1);
		for(int i = 1; i<= m; ++i)
		{
			int _s, _d, _w;
			cin >> _s >> _d >> _w;
			adjList[_s].push_back({ _d, _w, false });
			adjList[_d].push_back({ _s, _w, false });
		}

		vector<int> dest;
		for(int i = 1; i <=t; ++i)
		{
			int _d;
			cin >> _d;
			dest.push_back(_d);
		}
		std::sort(dest.begin(), dest.end());

		const int INF = 1'000'000'000;
		vector<int> table(n + 1, INF);
		table[s] = 0;
		vector<bool> visited(n + 1, false);

		std::priority_queue<tEdge, vector<tEdge>, std::greater<>> PQ;
		PQ.push({ s,0, false });
		while (!PQ.empty())
		{
			auto [cur, cw, cb] = PQ.top();
			PQ.pop();

			if (visited[cur]) continue;
			if (table[cur] >= cw && cb) visited[cur] = true;

			for (auto [nd, nw, nb] : adjList[cur])
			{
				if ( table[nd] >= cw + nw )
				{
					if (cb || (cur == g && nd == h) || (cur == h && nd == g))
					{
						nb = true;
					}
					table[nd] = cw + nw;
					PQ.push({ nd, table[nd], nb});
				}
			}
		}

		for (auto it : dest)
		{
			if(visited[it])
				cout << it << " ";
		}
		cout << "\n";
	}

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :