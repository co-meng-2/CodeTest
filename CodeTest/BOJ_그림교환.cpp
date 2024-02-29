#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <queue>

int main()
{
	fastio;

	int N;
	cin >> N;

	vector<vector<int>> mat(N);
	for (int i = 0; i < N; ++i)
	{
		std::string str;
		cin >> str;

		for (auto c : str)
		{
			mat[i].push_back(c - '0');
		}
	}

	// dp[i][j][k] i번 교환한 경우 j가 마지막 상인 k는 방문한 상인 마킹 / 최대 가격
	const int INF = 1'000'000'000;
	vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(1 << N, INF)));

	dp[0][0][1] = 0;
	int maxTradeCnt = 1;
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			for (int k = 0; k < (1 << N); ++k)
			{
				// 방문했다면
				if (k & (1 << j)) continue;
				for (int x = 0; x < N; ++x)
				{
					if (dp[i - 1][x][k] != INF && x != j && dp[i - 1][x][k] <= mat[x][j])
					{
						dp[i][j][k | (1 << j)] = std::min(mat[x][j], dp[i][j][k | (1 << j)]);
						maxTradeCnt = i + 1;
					}
				}
			}
		}
	}

	cout << maxTradeCnt;


	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :