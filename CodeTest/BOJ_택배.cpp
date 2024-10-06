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

// 플로이드의 경로
// 경유점 저장
int n, m;
int floyd[201][201];
int ans[201][201]{};

int main()
{
	fastio;

	memset(floyd, INF, sizeof(floyd));
	memset(ans, INF, sizeof(ans));
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		floyd[a][b] = w;
		floyd[b][a] = w;

		ans[a][b] = b;
		ans[b][a] = a;
	}

	for(int k = 1; k <=n; ++k)
		for(int i = 1; i <=n; ++i)
			for(int j = 1; j<=n; ++j)
			{
				if (i == j) continue;
				if(floyd[i][j] > floyd[i][k] + floyd[k][j])
				{
					floyd[i][j] = floyd[i][k] + floyd[k][j];
					ans[i][j] = ans[i][k];
				}
			}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (ans[i][j] == INF) cout << "- ";
			else
			{
				cout << ans[i][j] << " ";
			}
		}
		cout << "\n";
	}


	return 0;
}


// S : 2 30
// U : 2 32
// T : 2 40
// C : 2 58
// Total : 28min
