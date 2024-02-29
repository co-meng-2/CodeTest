#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// 9876543210
// x0123456789



// i�� �����ؼ� j�� ������ ��� ���� ���� �� �ֳ�?

int main()
{
	fastio;

	int N;
	cin >> N;

	long long mod = 1'000'000'000;

	// dp[i][j][k] : ���̰� i�̰� j�� ������. k�� ��Ʈ�� ���ݱ��� ������ ������ ������ �Ǵ�.
	// dp[i][j][k | (1 << j)] = dp[i-1][j-1 or j+1][k]
	vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(10, vector<long long>(1 << 10, 0)));

	for (int j = 1; j < 10; ++j)
	{
		dp[1][j][1 << j] = 1;
	}

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < (1 << 10); ++k)
			{
				if (j < 9)
				{
					dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
					dp[i][j][k | (1 << j)] %= mod;
				}
				if (j > 0)
				{
					dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
					dp[i][j][k | (1 << j)] %= mod;
				}
			}
		}
	}

	long long sum = 0;
	for (int j = 0; j < 10; ++j)
	{
		sum += dp[N][j][(1 << 10) - 1];
		sum %= mod;
	}
	//for (int i = 1; i <= 40; ++i)
	//{
	//	for (int j = 0; j < 10; ++j)
	//	{
	//		sum += dp[i][j][(1 << 10) - 1];
	//		sum %= mod;
	//	}
	//}

	cout << sum;
	
	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :