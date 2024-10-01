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

// a->b로 가는데 필요한 경유로를 저장
int layover[101][101]{};
int floyd[101][101]{};
int n, m;

void dfs(int s, int d, vector<int>& ans)
{
	if (layover[s][d] == 0) 
		return;

	dfs(s, layover[s][d], ans);
	ans.push_back(layover[s][d]);
	dfs(layover[s][d], d, ans);
}

int main()
{
	fastio;

	memset(floyd, INF, sizeof(floyd));

	cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		floyd[a][b] = min(floyd[a][b], w);
	}

	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <=n; ++i)
		{
			for(int j = 1; j<=n; ++j)
			{
				if (i == j)
					floyd[i][j] = 0;

				if(floyd[i][j] > floyd[i][k] + floyd[k][j])
				{
					floyd[i][j] = floyd[i][k] + floyd[k][j];
					layover[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (floyd[i][j] == INF)
				cout << 0 << " ";
			else
				cout << floyd[i][j] << " ";
		}
		cout << "\n";
	}

	for(int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j || floyd[i][j] == INF)
			{
				cout << 0 << "\n";
				continue;
			}

			vector<int> ans;
			ans.push_back(i);
			dfs(i, j, ans);
			ans.push_back(j);
			cout << ans.size() << " ";
			for(auto elem : ans)
			{
				cout << elem << " ";
			}
			cout << "\n";
		}
	}
	

	return 0;
}


// S : 2 28
// U : 2 29
// T : 2 33
// C : 3 11
// Total : 43min
