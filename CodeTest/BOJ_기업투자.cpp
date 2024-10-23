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

// knapsack

int n, m;
int board[21][301]{};
int dp[21][301]{};
pii trace[21][301]{};

int main()
{	
	fastio;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
		for (int j = 1; j <=m; ++j)
		{
			cin >> board[j][a];
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			for(int k = 0; k <= j; ++k)
			{
				if (dp[i][j] < dp[i - 1][j - k] + board[i][k])
				{
					dp[i][j] = dp[i - 1][j - k] + board[i][k];
					trace[i][j] = { i-1, j - k };
				}
			}
		}
	}

	vector<int> ans(m + 1);
	int ti = m, tj =n;
	while(ti > 0 && tj > 0)
	{
		auto [ni,nj] = trace[ti][tj];
		ans[ti] = tj - nj;
		ti = ni;
		tj = nj;
	}

	cout << dp[m][n] << "\n";
	for(int i = 1; i <= m; ++i)
	{
		cout << ans[i] << " ";
	}

	return 0;
}


// S : 12 04
// U : 12 06
// T : 
// C :
// Total :
