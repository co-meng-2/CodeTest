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

int dp[61][61][61]{};
int sub[3] = { 1,3,9 };

void dfs(int hp[3], int cnt)
{
	do
	{
		int nxthp[3]{};
		for(int i = 0; i < 3; ++i)
		{
			nxthp[i] = max(0, hp[i] - sub[i]);
		}
		if (dp[nxthp[0]][nxthp[1]][nxthp[2]] <= cnt + 1) continue;
		dp[nxthp[0]][nxthp[1]][nxthp[2]] = cnt + 1;
		dfs(nxthp, cnt + 1);
	} while (next_permutation(begin(sub), end(sub)));
}

int main()
{
	fastio;

	memset(dp, INF, sizeof(dp));

	int n;
	int hp[3]{};
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> hp[i];
	}

	dp[hp[0]][hp[1]][hp[2]] = 0;


	dfs(hp, 0);

	cout << dp[0][0][0];

	return 0;
}


// S : 816
// U : 817
// T : 827
// C : 847
// Total : 31min
