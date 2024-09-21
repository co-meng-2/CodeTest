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

// 중앙 -> 다른 2
// 다른 -> 인접 3 반대편 4 같은 지점 1
// dp의 냄새...

// y -> x
int adjMat[5][5]
{
	{0, 2, 2, 2, 2},
	{0, 1, 3, 4, 3},
	{0, 3, 1, 3, 4},
	{0, 4, 3, 1, 3},
	{0, 3, 4, 3, 1}
};

int dp[2][5][5]{};

int main()
{
	fastio;
	memset(dp, INF, sizeof(dp));

	int nxt;
	cin >> nxt;
	bool toggle = true;
	dp[toggle][0][0] = 0;
	while(nxt)
	{
		toggle = !toggle;
		for(int i = 0; i < 5; ++i)
			for(int j = 0; j < 5; ++j)
			{
				if (dp[!toggle][i][j] == INF) continue;

				dp[toggle][nxt][j] = min(dp[toggle][nxt][j], dp[!toggle][i][j] + adjMat[i][nxt]);
				dp[toggle][i][nxt] = min(dp[toggle][i][nxt], dp[!toggle][i][j] + adjMat[j][nxt]);
				dp[!toggle][i][j] = INF;
			}

		cin >> nxt;
	}

	int mn = INF;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			mn = min(dp[toggle][i][j], mn);

	cout << mn;

	return 0;
}


// S : 2:03
// U : 
// T : 
// C :
// Total :
