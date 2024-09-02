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

int p[50001]{};
int lv[50001]{};

int main()
{
	fastio;

	p[1] = -1;

	int n;
	cin >> n;
	vector<vector<int>> adjList(n + 1);
	for(int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	queue<int> Q;
	Q.push(1);

	int lvcnt = 1;
	while (!Q.empty())
	{
		int qsz = Q.size();
		while (qsz--)
		{
			auto cur = Q.front();
			Q.pop();

			for (auto nxt : adjList[cur])
			{
				if (p[nxt] != 0) continue;

				p[nxt] = cur;
				lv[nxt] = lvcnt;
				Q.push(nxt);
			}
		}
		lvcnt++;
	}

	int m;
	cin >> m;

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		if (lv[a] < lv[b]) // a -> child
			swap(a, b);
		while (lv[a] != lv[b])
		{
			a = p[a];
		}

		while(a != b)
		{
			a = p[a];
			b = p[b];
		}

		cout << a <<"\n";
	}

	return 0;
}


// S : 1:07
// U : 1:08
// T : 
// C :
// Total :
