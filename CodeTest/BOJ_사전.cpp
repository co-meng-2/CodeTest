#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <string>
#include <climits>

// 팩토리얼을 쓸 수 없다! (N+M)!/N!/M! 과정에서 각각의 팩토리얼에서 오버플로우가 발생가능하여 상대적으로 작은 수들만 받을 수 있음.
long long Factorial(int n, long long res = 1)
{
	if (res > (1LL << 63 - 1LL) / 100LL) 
		return 0;
	if (n == 1) return res;
	return Factorial(n-1, res * n);
}

int main()
{
	fastio;

	int N, M, K;
	cin >> N >> M >> K;

	long long dp[101][101]{};

	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 100; ++j)
		{
			if(i == 0 || j == 0)
				dp[i][j] = 1;
			else
			{
				// 조합 수 계산 + 오버플로우 방지 ( 10억 이상 값인지만 알면 됨. )
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				if (dp[i][j] > 1000000000) dp[i][j] = 1000000001;
			}
		}
	}

	if (dp[N][M] < K)
	{
		cout << -1;
		return 0;
	}
	
	std::string ans = "";


	int prevSum = 0;

	// 정답 갱신
	while (true)
	{
		// A선택하는 경우
		long long selectA = prevSum + dp[N-1][M];

		if (selectA >= K)
		{
			ans.push_back('a');
			N--;
		}
		// Z를 선택하는 경우
		else
		{
			// 사전에서 후 순위로 밀리기 때문에 A까지의 순위를 갱신해준다.
			prevSum = selectA;
			ans.push_back('z');
			M--;
		}

		// A나 Z중 하나를 다 썻을 때 나머지를 채워준다.
		if (N == 0)
		{
			while (M--)
			{
				ans.push_back('z');
			}
			break;
		}
		else if (M == 0)
		{
			while (N--)
			{
				ans.push_back('a');
			}
			break;
		}
			
	}

	for (auto it : ans)
	{
		cout << it;
	}
	

	return 0;
}


// S : 3:56
// U : 4:00
// T : 4:30
// C : 6:01
// Total : 1h 30