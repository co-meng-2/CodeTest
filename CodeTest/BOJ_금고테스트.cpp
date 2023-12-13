#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <cmath>
#include <climits>

// DP...

int main()
{
	fastio;
	int N, K;
	cin >> N >> K;

	// dp[i][j], i번째 층과 j개의 금고를 가지고 있을 때, 금고가 부서지는 층을 찾는 가장 적은 금고 낙하 횟수.
	vector<vector<int>> dp(N + 1, vector<int>(K + 1));

	for (int i = 1; i <= N; ++i)
		dp[i][1] = i;

	for (int i = 1; i <= K; ++i)
		dp[1][i] = 1;

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 2; j <= K; ++j)
		{
			dp[i][j] = INT_MAX;
			for (int x = 1; x <= i; ++x)
			{
				int res = 1 + std::max(dp[x - 1][j - 1], dp[i - x][j]);
				dp[i][j] = std::min(dp[i][j], res);
			}
		}
	}
	cout << dp[N][K];

	return 0;
}


// S : 3:34
// U : 3:35
// T : 3:45
// C : Failed
// Total :